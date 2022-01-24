#include <stdio.h>
int fibo_r(int n)
{
	return n < 2 ? n : fibo_r(n - 1) + fibo_r(n - 2);
}

int main()
{
	int sum = 0;
	int k = 0;
	while (fibo_r(k) < 4000000)
		++k;

	for (int i = 0; i < k; ++i)
		if (fibo_r(i) % 2 == 0)
			sum += fibo_r(i);

	printf("Sum of even values:%d\n", sum);
}
