// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

// Input:
// - First line: integer n (array size)
// - Second line: n space-separated integers
// - Third line: integer k (key to search)

// Output:
// - Line 1: "Found at index i" OR "Not Found"
// Line 2: "Comparisons = c"

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// Found at index 2
// Comparisons = 3

// Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;

    // Input 'n'
    scanf("%d", &n);

    // Allocate memory for array
    int *arr = (int*) malloc(sizeof(int) * n);

    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input 'k'
    scanf("%d", &k);

    int found = -1;
    int c = 0;

    // Search array for 'k'
    for (int i = 0; i < n; i++) {
        c++;

        if (arr[i] == k) {
            found = i;
            break;
        }
    }

    if (found > -1) printf("Found at index %d", found);
    else printf("Not Found");

    printf("\nComparisons = %d", c);

    free(arr);

    return 0;
}