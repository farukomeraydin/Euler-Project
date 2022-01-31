#include <stdio.h>
int main()
{
	int sum_of_squares = 0;
	int square_of_sum = 0;

	for (int i = 1; i <= 100; ++i)
		sum_of_squares += i * i;

	printf("sum_of_squares: %d\n", sum_of_squares);

	square_of_sum = 100 * 101 / 2;

	printf("square_of_sum: %d\n", square_of_sum * square_of_sum);

	printf("Difference: %d\n", square_of_sum * square_of_sum - sum_of_squares);
	return 0;
}
