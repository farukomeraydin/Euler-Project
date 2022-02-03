#include <stdio.h>

int main()
{	
	int a, b, c;

	a = 1;
	b = 2;
	c = 3;
	while (1) {
		for (a = 1; a < c; ++a)
			for (b = 1; b < c; ++b)
				if (a * a + b * b == c * c && a + b + c == 1000)
					goto EXIT;
		++c;
	}
EXIT:	
	printf("a:%d, b:%d, c:%d and abc = %d\n", a, b, c, a*b*c);
	return 0;
}
