

using luaL_register_t = void(__fastcall*)(lua_State* L, const char* libname, const luaL_Reg* l); // it will show as int for first arg, char for second and int again for third, thats just the pseudo. originally, this was meant for use with shuffles. 
// also, the type is void because this wont return anything
luaL_register_t luaL_register = reinterpret_cast<luaL_register_t>(0x0); // search "_LOADED", it should take 3 arguments. you SHOULD see top and base a lot 

// original: https://github.com/luau-lang/luau/blob/master/VM/src/laux.cpp
void luaL_register(lua_State* L, const char* libname, const luaL_Reg* l) // lib name can also be _G to apply globally
{
    if (libname)
    {
        int size = libsize(l);
        // check whether lib already exists
        luaL_findtable(L, LUA_REGISTRYINDEX, "_LOADED", 1); // string to search in disassembler, easiest way to find it. theres other ways of course.
        lua_getfield(L, -1, libname); // get _LOADED[libname]
        if (!lua_istable(L, -1))
        {                  // not found?
            lua_pop(L, 1); // remove previous result
            // try global variable (and create one if it does not exist)
            if (luaL_findtable(L, LUA_GLOBALSINDEX, libname, size) != NULL)
                luaL_error(L, "name conflict for module '%s'", libname);
            lua_pushvalue(L, -1);
            lua_setfield(L, -3, libname); // _LOADED[libname] = new table
        }
        lua_remove(L, -2); // remove _LOADED table
    }
    for (; l->name; l++)
    {
        // register
        lua_pushcfunction(L, l->func, l->name);
        lua_setfield(L, -2, l->name);
    }
}
