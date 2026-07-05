// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:
// 1:2 2:2 3:1

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    int freq[1001] = {0};

    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }

    for (int i = 0; i < 1001; i++) {
        if (freq[i] > 0) {
            printf("%d:%d ", i, freq[i]);
        }
    }

    puts("");

    free(arr);

    return 0;
}