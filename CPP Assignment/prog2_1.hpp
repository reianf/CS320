#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
#include <sstream>
#include <istream>
#include <exception>
#include <stdexcept>

using namespace std;

class Tokenizer {
	private:
		queue< vector<string> > tokensQueue;

	public:
		Tokenizer() {  //constructor makes sure memory is allocated
		} 
		~Tokenizer() { //destructor deletes that allocated memory
		} 
		void Tokenize(string s);
		vector<string> GetTokens();
};