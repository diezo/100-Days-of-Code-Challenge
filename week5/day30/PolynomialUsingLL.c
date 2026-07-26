// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Example:
// Input:
// 5
// 10 4
// 20 3
// 30 2
// 40 1
// 50 0

// Output:
// 10x^4 + 20x^3 + 30x^2 + 40x + 50

// Explanation:
// Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int c;
    int e;

    struct ListNode *next;
} ListNode;

void freeList(ListNode*);

int main() {
    int n;

    ListNode *head = NULL;
    ListNode *tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ListNode *node = malloc(sizeof(*node));
        scanf("%d", &node->c);
        scanf("%d", &node->e);
        node->next = NULL;

        if (head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    int first = 1;
    ListNode *temp = head;

    while (temp != NULL) {
        if (temp->c != 0) {
            if (!first) printf(" + ");
            first = 0;

            printf("%d", temp->c);

            if (temp->e > 0) {
                printf("x");

                if (temp->e > 1) {
                    printf("^%d", temp->e);
                }
            }
        }

        temp = temp->next;
    }
    puts("");

    freeList(head);

    return 0;
}

void freeList(ListNode *head) {
    while (head != NULL) {
        ListNode *temp = head->next;
        free(head);
        head = temp;
    }
}