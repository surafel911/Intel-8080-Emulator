#include <error.h>

#include <stdio.h>
#include <stdlib.h>

void
error(const char* message)
{
	printf("%s\n", message);
	abort();
}
