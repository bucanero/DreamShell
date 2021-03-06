/* DreamShell ##version##

   module.c - luaSTD module
   Copyright (C)2007-2013 SWAT 

*/
            
#include <kos.h>
#include <kos/exports.h>
#include "ds.h"

DEFAULT_MODULE_HEADER(luaSTD);

int tolua_STD_open(lua_State* tolua_S);


int lib_open(klibrary_t * lib) {
    tolua_STD_open(GetLuaState());
	RegisterLuaLib(lib_get_name(), (LuaRegLibOpen *)tolua_STD_open);
    return nmmgr_handler_add(&ds_luaSTD_hnd.nmmgr);
}


int lib_close(klibrary_t * lib) {
	UnregisterLuaLib(lib_get_name());
    return nmmgr_handler_remove(&ds_luaSTD_hnd.nmmgr); 
}





