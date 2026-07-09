// Problem: Given integers a and b, compute a^b using recursion without using pow() function.

// Input:
// - Two space-separated integers a and b

// Output:
// - Print a raised to power b

// Example:
// Input:
// 2 5

// Output:
// 32

// Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32

#include <stdio.h>
#include <stdlib.h>

unsigned long power(unsigned long, unsigned long);

int main() {
    unsigned long a, b;

    // Input 'a' and 'b'
    scanf("%lu %lu", &a, &b);

    printf("%lu", power(a, b));

    return 0;
}

unsigned long power(unsigned long a, unsigned long b) {
    if (b == 0) return 1;  // Base condition

    return a * power(a, b - 1);
}