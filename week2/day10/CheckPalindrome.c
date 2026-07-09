// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

// Explanation: String reads same forwards and backwards

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char*, int);

int main() {
    char str[100];

    // Input string
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);

    // Remove trailing '\n' character
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    puts(isPalindrome(str, len) ? "YES" : "NO");

    return 0;
}

bool isPalindrome(char *str, int len) {
    int l = 0;
    int r = len - 1;

    while (l < r) {
        if (str[l] != str[r]) return false;

        l++;
        r--;
    }

    return true;
}