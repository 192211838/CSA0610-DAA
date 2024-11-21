#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num, int divisor) {
    if (num <= 1) {
        return false; 
    }
    if (divisor == 1) {
        return true;
    }
    if (num % divisor == 0) {
        return false; 
    }
    return isPrime(num, divisor - 1); 
}
void printPrimes(int n, int current) {
    if (current > n) {
        return; 
    }
    
    if (isPrime(current, current / 2)) {
        printf("%d ", current); 
    }
    
    printPrimes(n, current + 1); 
}

int main() {
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);

    printf("Prime numbers from 1 to %d are: \n", n);
    printPrimes(n, 2); 
    
    return 0;
}
