// Problem: Create and Traverse Singly Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

int main() {
    int n;

    scanf("%d", &n);

    Node *root = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        Node *node = malloc(sizeof(Node));

        if (node == NULL) {
            perror("Memory allocation failed");
            return 1;
        }

        scanf("%d", &node->val);
        node->next = NULL;

        if (root == NULL) root = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    Node *node = root;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }

    puts("");

    return 0;
}