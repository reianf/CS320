#include "prog2_1.hpp"
using namespace std;

class Parser {
	public: 
		Parser() {  //constructor makes sure memory is allocated
		} 
		~Parser() { //destructor deletes that allocated memory
		} 
		bool Parse(vector<string> input);
};