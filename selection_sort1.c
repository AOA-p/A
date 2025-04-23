#include <stdio.h>

int main() {
    int arr[20], n, i, j, min_index, temp;

    printf("Enter the array size: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }
    printf("\nSorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
