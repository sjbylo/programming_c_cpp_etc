#include <stdio.h>
#include <stdlib.h>

int main()
{
	//int a[20];
	int* a = malloc(20);
	int len = 10;

	for (int i = 0; i < len; i++) {
		a[i] =0;
	}

	a[0] = 5;
	a[1] = 1;
	a[2] = 8;
	a[3] = 4;
	a[4] = 3;
	a[5] = 9;
	a[6] = 6;
	a[7] = 2;
	a[8] = 7;
	a[9] = 0;
	a[10] = 9999;

	for (int i = 0; i < len; i++) {
		printf ("%d, ", a[i] );
	}
	printf ("\n");

	int t;

	for (int j = 1; j < len; j++) {
		for (int i = 0; i < len-j; i++) {
			if (a[i] > a[i+1]) {
				t = a[i];
				a[i] = a[i+1];
				a[i+1] = t; 
			}
		}
	}

	for (int i = 0; i < len; i++) {
		printf ("%d, ", a[i] );
	}
	printf ("\n");
}


