// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (the array)
// - Third line: integer pos (1-based position)
// - Fourth line: integer x (element to insert)

// Output:
// - Print the updated array (n+1 integers) in a single line, space-separated

// Example:
// Input:
// 5
// 1 2 4 5 6
// 3
// 3

// Output:
// 1 2 3 4 5 6

// Explanation: Insert 3 at position 3, elements [4,5,6] shift right

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, x;

    // Input 'n'
    scanf("%d", &n);

    // Allocate array elements
    int *arr = (int*) malloc(sizeof(int) * n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input 'pos'
    scanf("%d", &pos);
    pos--;  // Make it 0-based position

    // Input 'x'
    scanf("%d", &x);

    // Resize array
    arr = (int*) realloc(arr, sizeof(int) * (n + 1));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int last = x;

    for (int i = pos; i < n + 1; i++) {
        int temp = arr[i];
        arr[i] = last;
        last = temp;
    }

    // Print the updated array
    printf("");
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}