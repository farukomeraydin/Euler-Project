#include <stdio.h>

#define TWO_MILLION		2000000

long long isprime_(long long val) {
	if (val == 0 || val == 1)
		return 0;
	if (val % 2 == 0)
		return val == 2;
	if (val % 3 == 0)
		return val == 3;
	if (val % 5 == 0)
		return val == 5;
	for (long long k = 7; k * k <= val; k += 2)
		if (val % k == 0)
			return 0;
	return 1;
}


int main()
{	
	long long sum = 2;
	long long i;
	for (i = 3; i < TWO_MILLION; i += 2)
		if (isprime_(i))
			sum += i;

	printf("Sum of primes below 2 million: %lli\n", sum);
	return 0;
}
