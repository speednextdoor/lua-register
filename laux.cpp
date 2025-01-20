 uintptr_t rebase(uintptr_t addy) { // simple rebasing
    return addy + reinterpret_cast<uintptr_t>(GetModuleHandleW(0));
}

using luaL_register_t = void(__fastcall*)(lua_State* L, const char* libname, const luaL_Reg* l); // it will show as int for first arg, char for second and int again for third, thats just the pseudo. originally, this was meant for use with shuffles. 
luaL_register_t luaL_register = reinterpret_cast<luaL_register_t>(rebase(0x22EF180)); // add addie with base adddie

// usage example
 static int hi(lua_State* L) // as stated, depends how you get lua state; i use the actual struct i use shuffles
 {
     r_print(1, "hi"); // whatever u want
     return 1;
 }

 static const luaL_Reg thunderlib[] = { // register under lib
     {"hi", hi}, // pushcfunction hi, setglobal hi you may think huh
     {"hitest2", hi}, // dont stop the commas but you can add as much as you want
     {NULL, NULL}, // 0 0
 };


 int shit(lua_State* L)
 {
     // now we set to _G or any other you can cast to uhh cache lib or crypt lib or anything:)
     // to register under lib, put anything but not _g it will just stay in that gc
     luaL_register(L, "_G", thunderlib); // globally into env, dont assign to any other tables lol ive seen exploits from years ago that had problems w this lol they didnt know _g existed
     return 1;
 }

// your final code should be smth like this
lua_State* luastatethingie; // now just cast your actual lua state  here
void main() {
shit(luastatethingie); // register funcs
}; //oops do not check commit history i thought it was luau (dementia problems 100%)
