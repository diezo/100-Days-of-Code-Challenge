// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

// Input:
// - First line: integer n representing number of rows and columns
// - Next n lines: n integers each representing the matrix elements

// Output:
// - Print "Identity Matrix" if the matrix satisfies the condition
// - Otherwise, print "Not an Identity Matrix"

// Example:
// Input:
// 3
// 1 0 0
// 0 1 0
// 0 0 1

// Output:
// Identity Matrix

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;

    // Input 'n'
    scanf("%d", &n);

    // Allocate memory for matrix
    int **matrix = malloc(sizeof(int*) * n);

    if (matrix == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // Input matrix elements
    for (int i = 0; i < n; i++) {
        int *row = malloc(sizeof(int) * n);

        if (row == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        for (int j = 0; j < n; j++) {
            scanf("%d", &row[j]);
        }

        matrix[i] = row;
    }

    bool res = true;

    // Check if matrix is an identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // Invalid diagonal element
            if (i == j && matrix[i][j] != 1) {
                res = false;
                goto end;
            }

            // Invalid off-diagonal element
            if (i != j && matrix[i][j] != 0) {
                res = false;
                goto end;
            }
        }
    }

    end:
    puts(res ? "Identity Matrix" : "Not an Identity Matrix");

    // Free matrix rows
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}