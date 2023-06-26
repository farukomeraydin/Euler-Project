#include <stdio.h>

int divisorSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int sum = 0;
    for (int i = 1; i < 10000; ++i) 
        if (i == divisorSum(divisorSum(i)) && i != divisorSum(i)) {
            sum += i;
            printf("Amicable Pairs: %d <==> %d\n", i, divisorSum(i));
        }
    printf("Sum of amicable numbers under 10.000: %d\n", sum);
    return 0;
}







