// Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

// Input:
// - First line: two integers r and c representing the number of rows and columns
// - Next r lines: c integers each representing the matrix elements

// Output:
// - Print all visited elements in the order of traversal, separated by spaces

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 1 2 3 6 9 8 7 4 5

// Explanation:
// The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

// Test Cases:

// Test Case 1:
// Input:
// 2 3
// 1 2 3
// 4 5 6
// Output:
// 1 2 3 6 5 4

// Test Case 2:
// Input:
// 3 1
// 7
// 8
// 9
// Output:
// 7 8 9

#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;

    // Input number of rows and cols
    scanf("%d %d", &r, &c);

    // Allocate memory for matrix
    int **matrix = malloc(sizeof(int*) * r);

    if (matrix == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // Input matrix elements
    for (int i = 0; i < r; i++) {
        int *row = malloc(sizeof(int) * c);

        if (row == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        for (int j = 0; j < c; j++) {
            scanf("%d", &row[j]);
        }

        matrix[i] = row;
    }

    // Define initial boundary
    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    while (1) {
        // Print top row
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }

        top++;
        if (top > bottom || left > right) break;

        // Print right column
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }

        right--;
        if (top > bottom || left > right) break;

        // Print bottom row
        for (int i = right; i >= left; i--) {
            printf("%d ", matrix[bottom][i]);
        }

        bottom--;
        if (top > bottom || left > right) break;

        // Print left column
        for (int i = bottom; i >= top; i--) {
            printf("%d ", matrix[i][left]);
        }

        left++;
        if (top > bottom || left > right) break;
    }

    puts("");

    // Free matrix rows
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}