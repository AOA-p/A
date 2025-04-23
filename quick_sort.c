#include <stdio.h>

// Function prototype
void quicksort(int a[], int first, int last);

int main() {
    int a[20], n, i;

    printf("Enter size of the array (max 20): ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n - 1);

    printf("Sorted elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int a[], int first, int last) {
    int pivot, i, j, temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;

            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}
