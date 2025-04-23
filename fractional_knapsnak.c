#include <stdio.h>
void main() {
    float weight[20], profit[20], capacity;
    int n, i, j;
    float ratio[20], fract, tp = 0, temp;

    printf("\nEnter the capacity of knapsack: ");
    scanf("%f", &capacity);

    printf("\nEnter the number of items: ");
    scanf("%d", &n);

    printf("\nEnter the weights and profits of each item:\n");
    for (i = 0; i < n; i++)
        scanf("%f %f", &weight[i], &profit[i]);

    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                // Swap weights
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
                // Swap profits
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > capacity)
            break;
        else {
            capacity -= weight[i];
            tp += profit[i];
        }
    }

    if (i < n) {
        fract = capacity / weight[i];
        tp += fract * profit[i];
    }

    printf("\nMaximum profit is: %.2f\n", tp);
}
