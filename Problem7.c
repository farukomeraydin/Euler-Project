#include <stdio.h>

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
	long long count = 6;
	long long i = 17;
	while (count != 10001) {
		if (isprime_(i))
			++count;
		i += 2;
	}

	printf("10001st prime: %lli\n", i-2);
		
	return 0;
}
