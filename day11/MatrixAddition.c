// Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the first matrix
// - Next m lines: n integers each representing the elements of the second matrix

// Output:
// - Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 9 8 7
// 6 5 4
// 3 2 1

// Output:
// 10 10 10
// 10 10 10
// 10 10 10

// Explanation:
// Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

// Test Cases:

// Test Case 1:
// Input:
// 2 2
// 1 2
// 3 4
// 5 6
// 7 8
// Output:
// 6 8
// 10 12

// Test Case 2:
// Input:
// 1 3
// 10 20 30
// 1 2 3
// Output:
// 11 22 33

// Test Case 3:
// Input:
// 3 1
// 1
// 2
// 3
// 4
// 5
// 6
// Output:
// 5
// 7
// 9

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;

    // Input 'm' and 'n'
    scanf("%d %d", &m, &n);

    int **matrixA = malloc(sizeof(int*) * m);
    int **matrixB = malloc(sizeof(int*) * m);

    // Check if memory allocation failed
    if (matrixA == NULL || matrixB == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // Input elements for matrix A
    for (int i = 0; i < m; i++) {
        int *row = malloc(sizeof(int) * n);

        // Check if memory allocation failed
        if (row == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        for (int j = 0; j < n; j++) {
            scanf("%d", &row[j]);
        }

        matrixA[i] = row;
    }

    // Input elements for matrix B
    for (int i = 0; i < m; i++) {
        int *row = malloc(sizeof(int) * n);

        // Check if memory allocation failed
        if (row == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        for (int j = 0; j < n; j++) {
            scanf("%d", &row[j]);
        }

        matrixB[i] = row;
    }

    // Print resultant matrix after addition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrixA[i][j] + matrixB[i][j]);
        }

        puts("");
    }

    // Free matrix rows
    for (int i = 0; i < m; i++) {
        free(matrixA[i]);
        free(matrixB[i]);
    }

    free(matrixA);
    free(matrixB);

    return 0;
}