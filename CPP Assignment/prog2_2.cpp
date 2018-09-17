#include "prog2_1.hpp"

using namespace std;

int main(int argc, char *argv[]){

	ifstream file(argv[1]);
	Tokenizer t;
	int i = 1;
	string a;
	stringstream ss;

	while(getline(file,a)){
		try{
			t.Tokenize(a);
		}
		catch(string s){
			cout << "Error on line " << i << ": " << s << endl;
			return 1;
		}
		i++;	
	}
	i--;	
	while(i != 0) {
		vector<string> token = t.GetTokens();
		int position = token[0].find( " " ); 

		while ( position != string::npos ) {
			token[0].replace( position, 1, "," );
			position = token[0].find( " ", position + 1 );
		}
		cout << token[0] << endl; 
		i--;
	}
}