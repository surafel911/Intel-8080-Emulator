#include <error.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void
error(const char* format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);

	printf("\n\n");

	abort();
}
