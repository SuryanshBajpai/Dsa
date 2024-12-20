#include <stdio.h>
#include <string.h>

// Function to perform linear search on an array of strings
int linearSearch(char *arr[], int size, char *target) {
    for (int i = 0; i < size; i++) {
        // Compare each string with the target
        if (strcmp(arr[i], target) == 0) {
            return i; // Target found
        }
    }
    return -1; // Target not found
}

int main() {
    char *arr[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int size = sizeof(arr) / sizeof(arr[0]);
    char *target = "cherry";

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element '%s' is present at index %d\n", target, result);
    } else {
        printf("Element '%s' is not present in array\n", target);
    }

    return 0;
}

