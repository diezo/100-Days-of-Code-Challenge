// Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the reversed array, space-separated

// Example:
// Input:
// 5
// 1 2 3 4 5

// Output:
// 5 4 3 2 1

// Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays

#include <stdio.h>
#include <stdlib.h>

void reverse(int*, int, int);

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

    reverse(arr, 0, n - 1);

    // Print modified array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}

void reverse(int *arr, int left, int right) {
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}
