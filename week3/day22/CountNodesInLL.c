// Problem: Count Nodes in Linked List

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

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        Node *node = malloc(sizeof(Node));
        scanf("%d", &node->val);
        node->next = NULL;

        if (head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    // Count nodes
    int count = 0;
    Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    free(temp);

    printf("%d\n", count);

    return 0;
}