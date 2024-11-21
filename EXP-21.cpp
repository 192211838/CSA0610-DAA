#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
void knapsack(int W, int weights[], int values[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; 
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    printf("Maximum value: %d\n", dp[n][W]);
    printf("Items included (index starts from 1): ");
    int w = W;
    for (int i = n; i > 0 && dp[i][w] > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i); 
            w -= weights[i - 1];
        }
    }
    printf("\n");
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];
    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    knapsack(W, weights, values, n);

    return 0;
}
