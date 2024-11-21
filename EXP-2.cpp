#include <stdio.h>
#include <math.h>
int armstrongRecursive(int num, int power) {
    if (num == 0) {
        return 0;
    }
    int digit = num % 10;
    return pow(digit, power) + armstrongRecursive(num / 10, power);
}
int countDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return 1 + countDigits(num / 10);
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    int numDigits = countDigits(number);
    int result = armstrongRecursive(number, numDigits);

    if (result == number) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}
