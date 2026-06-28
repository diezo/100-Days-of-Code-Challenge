// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer pos (1-based position to delete)

// Output:
// - Print the updated array with (n-1) elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 10 30 40 50

// Explanation: Delete position 2 (element 20), remaining elements shift left

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos;

    // Input 'n'
    scanf("%d", &n);

    // Allocate array
    int *arr = (int*) malloc(sizeof(int) * n);

    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input 'pos'
    scanf("%d", &pos);
    pos--;  // Convert to 0-based position

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Reallocate array to (n-1)
    arr = (int*) realloc(arr, sizeof(int) * (n - 1));

    if (arr == NULL) {
        printf("Memory reallocation failed");
        return 1;
    }

    // Print array elements
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}