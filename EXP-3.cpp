#include <stdio.h>
int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a; 
    }
    return gcdRecursive(b, a % b); 
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;

    int gcd = gcdRecursive(num1, num2);

    printf("The GCD of %d and %d is: %d\n", num1, num2, gcd);

    return 0;
}
