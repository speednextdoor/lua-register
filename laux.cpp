
// note i used luastate as first parameter bc i when I personally grab lua state i dont store to a int or dword or anything i cast to luastate FYI so you may need to change that part if you want its simple lol

using luaL_register_t = void(__fastcall*)(lua_State* L, const char* libname, const luaL_Reg* l); // it will show as int for first arg, char for second and int again for third, thats just the pseudo. originally, this was meant for use with shuffles. 
luaL_register_t luaL_register = reinterpret_cast<luaL_register_t>(0x0); // _LOADED search this string and you will see it you cannot miss it

// usage example
 static int hi(lua_State* L) // as stated, depends how you get lua state
 {
     r_print(1, "hi"); // whatever u want
     return 1;
 }

 static const luaL_Reg thunderlib[] = { // register under lib
     {"hi", hi}, // pushcfunction hi, setglobal hi 💯💯💯
     {"hitest2", hi}, // dont stop the commas but you can add as much as you want
     {NULL, NULL},
 };


 int shit(lua_State* L)
 {
     // now we set to _G or any other you can cast to uhh cache lib or crypt lib or anything:)
     luaL_register(L, "_G", thunderlib); // globally into env, dont assign to any other tables lol ive seen exploits from years ago that had problems w this lol they didnt know _g existed
     return 1;
 }

// your final code should be smth like this
void main(){
shit(luastatethingie);
end}
