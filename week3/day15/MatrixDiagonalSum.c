// // Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 15

// Explanation:
// 1 + 5 + 9 = 15

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    // Input 'm' and 'n'
    scanf("%d %d", &m, &n);

    // Allocate memory for matrix
    int **matrix = malloc(sizeof(int*) * m);

    if (matrix == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // Input matrix elements
    for (int i = 0; i < m; i++) {
        matrix[i] = malloc(sizeof(int) * n);

        if (matrix[i] == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;

    // Calculate sum of primary diagonal elements
    for (int i = 0; i < ((m < n) ? m : n); i++) {
        sum += matrix[i][i];
    }

    printf("%d\n", sum);

    // Free matrix rows
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}