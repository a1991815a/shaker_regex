#ifndef __SHAKER_ASSERT__
#define __SHAKER_ASSERT__
#include "shaker_define.h"

SHAKER_NS_START;

#if defined(_DEBUG)
#define SHAKER_ASSERT(cond, msg, ...) _CrtDbgReport(_CRT_ASSERT, __FILE__, __LINE__, nullptr, msg, __VA_ARGS__)
#else
#define SHAKER_ASSERT(cond, msg, ...) 
#endif

#define S_ASSERT(cond, msg) SHAKER_ASSERT(cond, msg)
#define SASSERT(cond, msg) S_ASSERT(cond, msg)
#define S_STATIC_ASSERT(cond, msg) static_cast(cond, msg)
#define SSTATIC_ASSERT(cond, msg) S_STATIC_ASSERT(cond, msg)

SHAKER_NS_END;
#endif