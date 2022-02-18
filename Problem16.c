#include <stdio.h>

#define SIZE	9999

long long power_(int base, int exp)
{
	long long result = 1;

	while (exp--)
		result *= base;

	return result;
}

int sum_digit_(int x)
{
	int sum = 0;

	while (x != 0) {
		sum += x % 10;
		x /= 10;
	}

	return sum;
}

int ndigit_(long long val) {
	if (val == 0)
		return 1;
	int digit_count = 0;
	while (val) {
		++digit_count;
		val /= 10;
	}
	return digit_count;
}

void display_array_(const int* ptr, size_t size) {
	for (size_t i = 0; i < size; ++i)
	{
		printf("%3d%c", ptr[i], i % 20 == 19 ? '\n' : ' ');
	}
}

int sum_array_(const int* p, int size)
{
	int sum = 0;

	while (size--) {
		sum += *p;
		++p;
	}

	return sum;
}

int a[SIZE];
int main()
{	
	int i = 9989;

	long long number = power_(2, 31);
	long long ten_power = power_(10, ndigit_(number) - 1);
	long long div_factor = number / ten_power;

	while (ten_power != 0) {
		a[i++] = (int)div_factor;
		ten_power /= 10;
		div_factor = number / ten_power % 10;
		if (ten_power == 1) {
			--ten_power;
			a[i] = div_factor % 10;
		}
	}

	int temp = 0;
	for (i = 0; i < 1000 - 31; ++i) {
		for (int k = 9998; k >= 1; --k) 
			a[k] *= 2;
		for (int k = 9998; k >= 1; --k)
			if (a[k] >= 10) {
				temp = a[k] / 10;
				a[k] %= 10;
				a[k - 1] += temp;
			}
	}
	printf("Sum of digits: %d\n",sum_array_(a, SIZE));

	return 0;
}
