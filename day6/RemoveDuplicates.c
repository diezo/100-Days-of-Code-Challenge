// Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (sorted array)

// Output:
// - Print unique elements only, space-separated

// Example:
// Input:
// 6
// 1 1 2 2 3 3

// Output:
// 1 2 3

// Explanation: Keep first occurrence of each element: 1, 2, 3

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Input 'n'
    scanf("%d", &n);

    // Allocate memory for array
    int *arr = (int*) malloc(sizeof(int) * n);

    // Check if memory allocation failed
    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int last = arr[0];

    printf("%d ", last);

    // Print unique elements
    for (int i = 1; i < n; i++) {
        if (arr[i] != last) {
            last = arr[i];
            printf("%d ", last);
        }
    }

    free(arr);

    return 0;
}