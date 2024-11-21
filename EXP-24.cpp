#include <stdio.h>
int reverse(int num, int rev) {
    if (num == 0) {
        return rev;
    } else {
        return reverse(num / 10, rev * 10 + num % 10);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int reversedNum = reverse(num, 0);
    printf("Reversed number: %d\n", reversedNum);

    return 0;
}
