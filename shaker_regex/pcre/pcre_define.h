#ifndef __PCRE_DEFINE__
#define __PCRE_DEFINE__

#pragma warning(disable:4005)

#if defined(_Console)
#define _CONSOLE
#endif
#if defined(_Debug)
#define _DEBUG
#else
#define _NDEBUG
#endif
#if defined(_Win32)
#define _WIN32
#endif
#if defined(_x86)
#define X86
#define _X86
#endif
#if defined(_Windows)
#define _WINDOWS
#endif


#pragma warning(default:4005)

#endif