#include <stdio.h>
int binomialCoefficient(int n, int k) {
    int dp[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    printf("Enter the values for n and k: ");
    scanf("%d %d", &n, &k);
    if (k < 0 || k > n) {
        printf("Invalid values for n and k.\n");
        return 0;
    }
    printf("C(%d, %d) = %d\n", n, k, binomialCoefficient(n, k));

    return 0;
}
