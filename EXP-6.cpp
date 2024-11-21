#include <stdio.h>
int isPrime(int n, int divisor) {
    if (n <= 1) {
        return 0; 
    }
    if (divisor == 1) {
        return 1; 
    }
    if (n % divisor == 0) {
        return 0; 
    }
    return isPrime(n, divisor - 1); 
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isPrime(number, number / 2)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}
