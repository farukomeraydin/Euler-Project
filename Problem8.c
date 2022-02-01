#include <stdio.h>
#include <stdlib.h>

#define SIZE	1000

int main()
{	
	FILE* f;
	if ((f = fopen("test.txt", "r")) == NULL) { /*All the digits are copied to a text file so we need to open it*/
		fprintf(stderr, "cannot read file!..\n");
		exit(EXIT_FAILURE);
	}

	int c, i = 0;
	short* pd;

	if ((pd = (short*)malloc(SIZE * sizeof(short))) == NULL) {
		fprintf(stderr, "cannot allocate memory!..\n");
		exit(EXIT_FAILURE);
	}

	while ((c = fgetc(f)) != EOF) /*Read every digit from file except newlines*/
	{
		if (c == '\n')
			continue;
		pd[i] = c;
		++i;
	}

	long long product = 1;
	long long max = 0;
	long long temp = 1;
	int m, n;
	for (m = 0; m < SIZE - 14; ++m) {
		for (n = m; n < m + 13; ++n) {
			temp *= (pd[n]-48); //ASCII to number
		}
		if (temp > max)
			max = temp;
		temp = 1;
	}

	printf("Max product of 13 adjacent digits is %lli.\n", max);

	return 0;
}
