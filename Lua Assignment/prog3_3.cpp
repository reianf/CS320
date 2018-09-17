extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	lua_State * L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L, argv[1]);
	string input;	
	
	getline(cin, input);
	lua_getglobal(L, "InfixToPostfix");
	lua_pushstring(L, input.c_str());
	lua_pcall(L, 1, 1, 0);
	//if function returns a string then print out postfix string, if not then print out error
	if(luaL_checkstring(L, 1)) cout << lua_tostring(L, 1) << endl;
	else 
	    cout << "Error" << endl;
	lua_close(L);
	return 0;
}