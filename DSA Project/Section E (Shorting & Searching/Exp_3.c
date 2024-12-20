#include <stdio.h>
#include <string.h>
// Function to perform binary search on an array of strings
int binarySearch(char *arr[], int size, char *target) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Compare target with mid element
        int result = strcmp(arr[mid], target);
        // If target is found
        if (result == 0) {
            return mid; // Target found
        }
        // If target is greater, ignore the left half
        else if (result < 0) {
            low = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }
    // Target not found
    return -1;
}
int main() {
    char *arr[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int size = sizeof(arr) / sizeof(arr[0]);
    char *target = "date";
    int result = binarySearch(arr, size, target);
    if (result != -1) {
        printf("Element '%s' is present at index %d\n", target, result);
    } else {
        printf("Element '%s' is not present in array\n", target);
    }

    return 0;
}

