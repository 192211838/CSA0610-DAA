#include <stdio.h>

void multiplyMatrices(int a[][10], int b[][10], int result[][10], int n, int *operations) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
                (*operations)++; 
            }
        }
    }
}

void printMatrix(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, operations = 0;
    int a[10][10], b[10][10], result[10][10];
    printf("Enter the size of the matrices (n x n): ");
    scanf("%d", &n);
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    multiplyMatrices(a, b, result, n, &operations);
    printf("Resultant Matrix:\n");
    printMatrix(result, n);
    printf("Total number of operations (multiplications + additions): %d\n", operations);

    return 0;
}
