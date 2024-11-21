#include <stdio.h>

void findMinMax(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];  
        }
        if (arr[i] > *max) {
            *max = arr[i];  
        }
    }
}

int main() {
    int n, min, max;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findMinMax(arr, n, &min, &max);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
