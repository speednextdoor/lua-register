

using luaL_register_t = void(__fastcall*)(lua_State* L, const char* libname, const luaL_Reg* l); // it will show as int for first arg, char for second and int again for third, thats just the pseudo. originally, this was meant for use with shuffles. 
luaL_register_t luaL_register = reinterpret_cast<luaL_register_t>(0x0); 

// usage
 static int hi(lua_State* L)
 {
     r_print(1, "hi"); // whatever u want
     return 1;
 }

 static const luaL_Reg thunderlib[] = {
     {"printnigger", hi},
     {NULL, NULL},
 };


 int shit(lua_State* L)
 {
     luaL_register(L, "_G", thunderlib); // globally into env, dont assign to any other tables lol ive seen exploits from years ago that had problems w this lol they didnt know _g existed

     return 1;
 }
