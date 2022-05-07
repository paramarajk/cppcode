#include <stdio.h> 
#include <string.h> 
int main()
{
	char csrc[100] = "Geeksfor";
	//memcpy(csrc+5, csrc, strlen(csrc)+1); 
	memmove(csrc + 5, csrc, strlen(csrc) + 1);
	printf("%s\n", csrc);
	return 0;
}
