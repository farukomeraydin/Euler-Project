#include <stdio.h>
#include <stdlib.h>

#define max_(a, b)	((a) > (b) ? (a) : (b))	//max macro

int main()
{	
	FILE* f;
	int a[20][20];

	if ((f = fopen("test.txt", "r")) == NULL) { //Numbers are copied to text file. Numbers like 08, 02 had their zero removed manually.
		fprintf(stderr, "Cannot read file!..\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < 20; ++i)
		for (int k = 0; k < 20; ++k)
			fscanf(f, "%d", &a[i][k]);
		
	int i, k;
	int product = 1;
	int vertical_max = 0, horizontal_max = 0, diagonal_max1 = 0, diagonal_max2 = 0;
	for (i = 0; i < 20; ++i)
		for (k = 0; k < 17; ++k) {
			product = a[i][k] * a[i][k + 1] * a[i][k + 2] * a[i][k + 3];
			if (product > horizontal_max)
				horizontal_max = product;
		}
	printf("Horizontal max: %d\n", horizontal_max);

	for (i = 0; i < 17; ++i)
		for (k = 0; k < 20; ++k) {
			product = a[i][k] * a[i+1][k] * a[i+2][k] * a[i+3][k];
			if (product > vertical_max)
				vertical_max = product;
		}

	printf("Vertical max: %d\n", vertical_max);
	
	for (i = 0; i < 17; ++i)
		for (k = 0; k < 17; ++k) {
			product = a[i][k] * a[i + 1][k + 1] * a[i + 2][k + 2] * a[i + 3][k + 3];
			if (product > diagonal_max1)
				diagonal_max1 = product;
		}

	printf("Diagonal max1: %d\n", diagonal_max1);

	for (i = 0; i < 17; ++i)
		for (k = 19; k > 2; --k) {
			product = a[i][k] * a[i + 1][k - 1] * a[i + 2][k - 2] * a[i + 3][k - 3];
			if (product > diagonal_max2)
				diagonal_max2 = product;
		}

	printf("Diagonal max2: %d\n", diagonal_max2);
	printf("Ultimate max product:%d\n", max_(max_(diagonal_max1, diagonal_max2), max_(horizontal_max, vertical_max)));
	return 0;
}
