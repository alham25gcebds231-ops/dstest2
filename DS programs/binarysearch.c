#include <stdio.h>
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    if (low > high) {
        return -1;
    }
    do {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    } while (low <= high);

    return -1;
}
int main() {
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int target;
    printf("Enter element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Success: Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    return 0;
}