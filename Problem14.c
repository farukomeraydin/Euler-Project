#include <stdio.h>

#define ONE_MILLION		1000000

int iseven_(int x)
{
	return x % 2 == 0;
}

int main()
{	
	unsigned int n = ONE_MILLION - 1;
	unsigned int temp = ONE_MILLION - 1;
	unsigned int x = 0;
	unsigned int count = 1;
	unsigned int max = 0;
	while (temp > 1) {
		n = temp;
		while (n != 1) {
			if (iseven_(n)) {
				n /= 2;
				++count;
			}
			else {
				n = 3 * n + 1;
				++count;
			}
		}
		if (max < count) {
			max = count;
			x = temp;
		}
		count = 1;
		--temp;
	}
	printf("Max term is produced by %d and there are %d terms\n", x, max);
	return 0;
}
