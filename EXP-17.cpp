#include <stdio.h>
typedef struct {
    int min;
    int max;
} MinMax;
MinMax findMinMax(int arr[], int left, int right) {
    MinMax result, leftResult, rightResult;
    if (left == right) {
        result.min = arr[left];
        result.max = arr[left];
        return result;
    }
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            result.min = arr[left];
            result.max = arr[right];
        } else {
            result.min = arr[right];
            result.max = arr[left];
        }
        return result;
    }
    int mid = (left + right) / 2;
    leftResult = findMinMax(arr, left, mid);
    rightResult = findMinMax(arr, mid + 1, right);
    result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
    result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;

    return result;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7, 19, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    MinMax result = findMinMax(arr, 0, n - 1);
    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);

    return 0;
}
