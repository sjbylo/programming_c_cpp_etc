#include <stdio.h>
//#include <stdlib.h>

//int main(int argc, char* argv[])
int main(int argc, char** argv)
{
	char* c[20];

	// Two ways to parse the argv (vector) array. 
	for ( int i = 0; i < argc; i++ )
	{
		printf ("%s\n", argv[i]);
	}

	char** tmp = argv;
	for ( char* arg = *argv ; arg != NULL; arg = *(++argv) )
	{
		printf ("%s\n", arg);
		//arg = *argv;
	}

	// Now, reverse the list
	argv = tmp;
	int j = 0;
	for ( int i = argc - 1; i >= 0; i-- )
	{
		c[j++] = argv[i];
		printf ("add: %s\n", argv[i]);
	}
	
	for ( int i = 0; i < argc; i++ ) {
		printf ("%s\n", c[i]);
	}
}

