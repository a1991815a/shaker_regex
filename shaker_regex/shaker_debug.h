#ifndef __SHAKER_DEBUG__
#define __SHAKER_DEBUG__
#include "shaker_define.h"
#if defined(_Console)
#include <iostream>
#else
#include <windows.h>
#endif

SHAKER_NS_START;

#if defined(_Console)
	#ifdef _DEBUG
#define SHAKER_DEBUG(str, ...) debug_console(str, __VA_ARGS__)
	#else
#define SHAKER_DEBUG(str, ...) 
	#endif
void debug_console(const char* format, ...);
#else
	#ifdef _DEBUG
#define SHAKER_DEBUG(str, ...) debug_win32(str, __VA_ARGS__)
	#else
#define SHAKER_DEBUG(str, ...) 
	#endif
void debug_win32(const char* format, ...);
#endif


SHAKER_NS_END;
#endif