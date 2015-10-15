#ifndef __LUA__
#define __LUA__

#if defined(__cplusplus)
extern "C" {
#include "lua.h"
#include "luaconf.h"
#include "lualib.h"
#include "lauxlib.h"
}
#else
#include "lua.h"
#include "luaconf.h"
#include "lualib.h"
#include "lauxlib.h"
#endif

#if defined(_DEBUG)
#pragma comment(lib, "./lua/luad.lib")
#else
#pragma comment(lib, "./lua/lua.lib")
#endif

#endif