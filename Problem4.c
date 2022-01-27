#include <stdio.h>

#define LARGEST_DECIMAL	100000

int ndigits(int val) {
	if (val == 0)
		return 1;
	int digit_count = 0;
	while (val) {
		++digit_count;
		val /= 10;
	}
	return digit_count;
}

int ispal(int val) {
	if ((val / LARGEST_DECIMAL) == (val % 10) && ((val / (LARGEST_DECIMAL / 10)) % 10) == ((val % 100) / 10) && ((val / (LARGEST_DECIMAL / 100)) % 10) == ((val % 1000) / 100))
		return 1;
	else
		return 0;
}


int main()
{
	int i, k = 0, x = 0, m = 0, n = 0;
	for (i = 10000; i <= (999*999); ++i)
		if (ispal(i)) 
			for (k = 100; k < i; ++k)
				if (i % k == 0 && ndigits(k) == 3 && ndigits(i / k) == 3) {
					m = i;
					n = k;
					x = i;
				}
	printf("%d x %d = %d\n", n, (m / n), m);
	printf("Largest palindrome number:%d\n", x);
	return 0;
}
