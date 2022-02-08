#include <stdio.h>
#include <stdlib.h>

long long numberOfDivisors(long long x) {
	int count = 0;
	for (long long i = 1; i * i <= x; ++i) 
		if (x % i == 0)
			count += 2;
	
	return count;
}

int main()
{	
	long long value;
	int count = 0;
	long long n = 1000;
	value = n * (n + 1) / 2;
	while (numberOfDivisors(value) < 500) {
		value = n * (n + 1) / 2;
		++n;
	}
	printf("First Triangle number that has more than 500 divisors:%lli\n", value);
	return 0;
}
