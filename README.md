# lua-register

lual register for exploits. you can find it at laux.cpp at https://github.com/roblox/luau

luaL_register takes a list of C functions and registers them allowing you to gain function access

it takes 3 parameters which is lua_State* L, const char* libname, const luaL_Reg* l

# how to use?

find the luaL_register address in disassembly by locating any laux.cpp functions
or you can type _LOADED and you can view it like that
ps: you can also find luaL->findtable

