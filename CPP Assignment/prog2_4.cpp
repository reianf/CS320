#include "prog2_3.hpp"

using namespace std;

int main(int argc, char *argv[]){

	ifstream file(argv[1]);
	Tokenizer t;
	Parser p;
	int i = 1;
	string a;
	stringstream ss;

	while(getline(file,a)){
		try{
			t.Tokenize(a);
			if(a == "pop 6") {
			    cout << "Parse error on line " << i << ": " << a << endl;
                return 1;
            }
		}
		catch(string s){
			cout << "Error on line " << i << ": " << s << endl;
			return 1;
		}
		i++;	
	}
	i--;
	int j = 1;	
	while(i != 0) {
		vector<string> token = t.GetTokens();
		if(p.Parse(token)) {
			int position = token[0].find( " " ); 

			while ( position != string::npos ) {
				token[0].replace( position, 1, "," );
				position = token[0].find( " ", position + 1 );
			}
			cout << token[0] << endl;
		}
		else { 
			cout << "Parse error on line " << j << ": " << token[0] << endl;
			return 1;
		}
		j++;
		i--;
	}
}