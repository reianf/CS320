#include "prog2_1.hpp"

using namespace std;

void Tokenizer::Tokenize(string s) {

	vector<string> tokens;
	stringstream ss;
	char arr[100];
	string valid[] = {"push", "pop", "add", "sub", "mul", "div", "mod", "skip", "save", "get"};
	bool boolean; 
	ss.str(s);

	//loop to check if each token is valid & if not, throw error 
	while(ss.getline(arr,100,' ')) { 
		ss << "";
		ss.clear();
		string toke(arr);
		boolean = false;
		//to check if token is a valid token word 
		for(int i = 0; i < 11; i++) {
			if(toke == valid[i]) boolean = true;
		}
		//if not a digit, throw error
		if(!boolean) {
			for(int j = 0; toke.length()-1 > j ;j++) {
				if(!isdigit(toke[j])) throw ("Unexpected token: " + toke);
			}
		}

	}

	tokens.push_back(s);
	tokensQueue.push(tokens);  //pushing tokens into vector fam
} 

vector<string> Tokenizer::GetTokens() {
	if(tokensQueue.empty())
		throw runtime_error("No tokens");

	vector<string> line = tokensQueue.front();
	tokensQueue.pop(); //deletes first item in queue & returns remaining 
	//back to keep tokenizing
	return line;

}