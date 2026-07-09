// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3

#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
void reverse(int*, int, int);

int main() {
    int n, k;
    int *arr;

    scanf("%d", &n);

    arr = malloc(sizeof(int) * n);

    if (arr == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    reverse(arr, 0, n - 1);
    reverse(arr, 0, (k % n) - 1);
    reverse(arr, k % n, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    puts("");

    free(arr);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int left, int right) {
    while (left < right) {
        swap(&arr[left], &arr[right]);

        left++;
        right--;
    }
}