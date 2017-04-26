#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int* a = malloc(20);
	int len = 10;

	for (int i = 0; i < len; i++) {
		a[i] =0;
	}

	*a = 1;
	a[1] = 2;
	*(a+2) = 3;
	*(a+3) = 4;
	a[4] = 5;

	for (int i = 0; i < len; i++) {
		printf ("%d, ", a[i] );
	}
	printf ("\n");

	// String stuff

	char* str;
	str = (char*) malloc(20);
	//str = "hello";
	strcpy(str, "hello");
	printf ("str = '%s' addr = %u\n", str, (unsigned int) str );

	str = (char*) realloc(str, 40);
	strcat (str, " world");
	printf ("str = '%s' addr = %u\n", str, (unsigned int) str );

	free (a);
	free (str);
	return (0);
}
