#include "prog2_3.hpp"
#include <cstring>
using namespace std;

bool Parser::Parse(vector<string> input) {
	stringstream ss;
	char arr[100];
	string valid[] = {"pop", "add", "sub", "mul", "div", "mod", "skip"};
	int i = 0;
	string dec;	
	ss << input[0];
	string toke = ss.str();
	//loop to check if each token is valid & if not, throw error 
	while(ss.getline(arr,100,' ') && i < 2) { 
		ss << "";
		ss.clear();
		i++;
	}
	if(i == 1) {
		for(int j = 0; 7 > j ;j++) {
			if(toke == valid[j]) return true;
		}
		return false;
	}
	else {
		memset(&arr,0, sizeof(arr)); 
		for(int k = 0; toke.length()-1 > k ;k++) {
			arr[k] = toke[k];
			if(toke[k] == ' ') {
				arr[k] = '\0';
				string s(arr);
				for(int j = 0; 7 > j ;j++) {
					if(s == valid[j]) return false;
				}	
			}
		}
		size_t pos = toke.find(" ");
		toke = toke.substr(pos + 1);
		for(int j = 0; toke.length()-1 > j ;j++) {
			if(!isdigit(toke[j])) return false;
		}
		return true;
	} 
}