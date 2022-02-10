#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void display_array_(const int* ptr, size_t size) {
	for (size_t i = 0; i < size; ++i)
	{
		printf("%3d%c", ptr[i], i % 20 == 19 ? '\n' : ' ');
	}
}

int main()
{	
	FILE* f;
	size_t row = 100, col = 50;
	if ((f = fopen("test.txt", "r")) == NULL) { /*Digits are copied to a text file, they need to be read.*/
		fprintf(stderr, "Cannot read file!..\n");
		exit(EXIT_FAILURE);
	}
	/*Dynamic memory allocation of a matrix*/
	int** pd = (int**)malloc(row * sizeof(int*));
	if (!pd) {
		fprintf(stderr, "cannot allocate rows!..\n");
		exit(EXIT_FAILURE);
	}

	for (size_t k = 0; k < row; ++k) {
		pd[k] = (int*)malloc(col * sizeof(int));
		if (!pd[k]) {
			fprintf(stderr, "cannot allocate columns!..\n");
			exit(EXIT_FAILURE);
		}
	}

	int c, i, k;

	for (i = 0; i < row; ++i) 
		for (k = 0; k <= col; ++k) {
			c = fgetc(f);
			if (c == '\n' || c == EOF)
				break;

			pd[i][k] = c - 48;
		}

	fclose(f);

	int sum[50] = {0}; 
	for (size_t m = 0; m < col; ++m) 
		for (size_t n = 0; n < row; ++n)
			sum[m] += pd[n][m];


	for (size_t m = 0; m < row; ++m)
		free(pd[m]);

	free(pd);

	for (int j = 49; j > 0; --j) {
		int other = sum[j] / 10;
		int remaining = sum[j] % 10;
		sum[j] = remaining;
		sum[j - 1] += other;
	}
	
	display_array_(sum, 50);
	printf("\nFirst Ten Digits of Sum: \n");
	for (int j = 0; j < 8; ++j) //First element of array has 3 digit number which is why we only need to check 8 elements.
		printf("%d", sum[j]);
	
	return 0;
}

