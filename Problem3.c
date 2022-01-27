#include <stdio.h>
#include <time.h>

int isprime_(long long val) {
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
	long long number = 600851475143;
	clock_t start = clock();
	
	if (number % 2 == 0) {
		if (isprime_(number)) {
			printf("%lli\n", number);
			goto pass;
		}
		int i = 2;
		while (i <= number)
		{
			if (isprime_(i) && (number % (long long)i) == 0) {
				printf("%d\n", i);
				number /= i;
			}

			++i;
		}
	}
	if (number % 2 != 0) {
		if (isprime_(number)) {
			printf("%lli\n", number);
			goto pass;
		}
		int i = 3;
		while (i <= number)
		{
			if (isprime_(i) && (number % (long long)i) == 0) {
				printf("%d\n", i);
				number /= i;
			}

			i += 2;
		}
	}
	clock_t end = clock();
	double sec = (double)(end - start) / CLOCKS_PER_SEC;
	printf("It took %f seconds\n", sec);
pass:


	return 0;
}
