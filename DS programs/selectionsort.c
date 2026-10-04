#include <stdio.h>

void selectionSort(int a[], int n) {
    int i, j, min_idx, temp;
    for(i = 0; i < n - 1; i++) {
        min_idx = i;
        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            temp = a[min_idx];
            a[min_idx] = a[i];
            a[i] = temp;
        }
    }
}

void printArray(int a[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nBefore sorting:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("After sorting:\n");
    printArray(arr, n);

    return 0;
}