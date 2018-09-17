extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, argv[1]);
    lua_close(L);
    return 0;
}