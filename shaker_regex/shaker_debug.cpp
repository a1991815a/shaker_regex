#include "shaker_debug.h"
#include <stdarg.h>
#include <stdio.h>

SHAKER_NS_START;

#if defined(_Console)
void debug_console(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	vprintf_s(format, ap);
	va_end(ap);
	printf("\n");
}
#else
void debug_win32(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	int len = vsnprintf_s(nullptr, 0, UINT_MAX, format, ap);
	char* buf = new char[len + 1];
	memset(buf, 0, len + 1);
	vsprintf_s(buf,len + 1, format, ap);
	OutputDebugStringA(buf);
	OutputDebugStringA("\n");
	delete[] buf;
	va_end(ap);
}
#endif

SHAKER_NS_END;