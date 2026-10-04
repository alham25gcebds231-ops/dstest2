#include <stdio.h>

void insertionSort(int a[], int n) {
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        
        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
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

    insertionSort(arr, n);

    printf("After sorting:\n");
    printArray(arr, n);

    return 0;
}