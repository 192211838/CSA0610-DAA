#include <stdio.h>
void addMatrix(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}
void subtractMatrix(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}
void strassenMatrixMultiplication(int A[2][2], int B[2][2], int result[2][2]) {
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];
    int A1[2][2], A2[2][2], B1[2][2], B2[2][2];
    A1[0][0] = A[0][0];
    A1[0][1] = A[0][1];
    A1[1][0] = A[1][0];
    A1[1][1] = A[1][1];

    B1[0][0] = B[0][0];
    B1[0][1] = B[0][1];
    B1[1][0] = B[1][0];
    B1[1][1] = B[1][1];
    int temp1[2][2], temp2[2][2];
    addMatrix(A1, A1, temp1);
    addMatrix(B1, B1, temp2);
    strassenMatrixMultiplication(temp1, temp2, M1);
    addMatrix(A2, A1, temp1);
    strassenMatrixMultiplication(temp1, B1, M2);
    subtractMatrix(B1, B2, temp1);
    strassenMatrixMultiplication(A1, temp1, M3);
    subtractMatrix(B2, B1, temp1);
    strassenMatrixMultiplication(A2, temp1, M4);
    addMatrix(A1, A2, temp1);
    strassenMatrixMultiplication(temp1, B2, M5);
    subtractMatrix(A2, A1, temp1);
    addMatrix(B1, B2, temp2);
    strassenMatrixMultiplication(temp1, temp2, M6);
    subtractMatrix(A2, A1, temp1);
    addMatrix(B2, B1, temp2);
    strassenMatrixMultiplication(temp1, temp2, M7);
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};   
    int B[2][2] = {{5, 6}, {7, 8}};   
    int result[2][2];                
    strassenMatrixMultiplication(A, B, result);
    printf("Result of Strassen's Matrix Multiplication:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
