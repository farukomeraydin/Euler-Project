#include <stdio.h>

int main()
{
    int factorial[200];  // An array to store the digits of the factorial
    int carry = 0;       // Carry for multiplication and addition
    int sum = 0;         // Variable to store the sum of digits
    int i, j;

    factorial[0] = 1;
    int num_digits = 1;

    for (i = 2; i <= 100; i++) {
        for (j = 0; j < num_digits; j++) {
            int product = factorial[j] * i + carry;
            factorial[j] = product % 10;
            carry = product / 10;
        }

        while (carry > 0) {
            factorial[num_digits] = carry % 10;
            carry = carry / 10;
            num_digits++;
        }
    }

    for (i = 0; i < num_digits; i++) 
        sum += factorial[i];
    
    printf("The sum of the digits in 100! is: %d\n", sum);
    return 0;
}

