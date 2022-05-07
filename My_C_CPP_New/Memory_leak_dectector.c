#include <stdio.h>
#include <stdlib.h>
#define malloc(X) my_malloc(X, __FILE__, __LINE__, __FUNCTION__)

void* my_malloc(size_t size, const char* file, int line, const char* func) {
	void* p = malloc(size);
	printf("Allocated = %s, %i, %s, %p[%li]\n", file, line, func, p, size);
	/*Link List functionality goes in here*/
	return p;
}
