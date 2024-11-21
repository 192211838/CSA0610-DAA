#include <stdio.h>
#include <limits.h>
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}
void optimalBST(int keys[], int freq[], int n) {
    int cost[n][n]; 
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }
    for (int len = 2; len <= n; len++) { 
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    printf("Optimal Cost of Binary Search Tree: %d\n", cost[0][n - 1]);
}

int main() {
    int n;

    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];
    printf("Enter the keys: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    optimalBST(keys, freq, n);

    return 0;
}
