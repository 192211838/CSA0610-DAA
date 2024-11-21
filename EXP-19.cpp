#include <stdio.h>
typedef struct {
    int weight;
    int value;
    float ratio; 
} Item;
int compare(const void *a, const void *b) {
    float ratioA = ((Item *)a)->ratio;
    float ratioB = ((Item *)b)->ratio;
    if (ratioA > ratioB) return -1;
    else if (ratioA < ratioB) return 1;
    else return 0;
}
float knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare);
    
    float totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight; 
    }
    float maxValue = knapsack(items, n, capacity);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
