// // Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

// Input:
// - Single line: a lowercase string containing only alphabetic characters (no spaces)

// Output:
// - Print the transformed code name after applying the mirror operation

// Example:
// Input:
// hello

// Output:
// olleh

// Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char*, char*);
void reverse(char*, int);

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

    reverse(str, len);

    printf("%s\n", str);

    return 0;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char *str, int len) {
    int left = 0;
    int right = len - 1;

    while (left < right) {
        swap(&str[left], &str[right]);

        left++;
        right--;
    }
}