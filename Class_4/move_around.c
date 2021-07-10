#include <stdio.h>

int main()
{
	char message[] = "Hello world! I am excited to be learning about pointers today.";
	char *submessage = &message[6]; // everything including and after world
									// why the dereferencing &?
	printf("%s", &message[6]);
	



	return 0;
}
