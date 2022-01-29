#include <stdio.h>

int main()
{
	int i;
	int k;
	int count = 0;
	for (i = 20; ; i += 2) {
		count = 0;
		for (k = 1; k <= 20; ++k) {
			if (i % k == 0)
				++count;
			else
				k = 21;
		}
		if (count == 20) {
			count = i;
			break;
		}
	}
	printf("Smallest number is: %d\n", count);
	return 0;
}
