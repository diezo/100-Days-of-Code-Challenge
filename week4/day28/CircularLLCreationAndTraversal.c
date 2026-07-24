// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

void freeCircularList(ListNode*);

int main() {
    int n;

    ListNode *head = NULL;
    ListNode *tail = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ListNode *node = malloc(sizeof(*node));
        scanf("%d", &node->val);
        node->next = NULL;

        if (head == NULL) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    // Point tail node's next pointer to head
    if (tail != NULL) tail->next = head;

    ListNode *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;

        if (temp == head) break;
    }
    puts("");

    freeCircularList(head);

    return 0;
}

void freeCircularList(ListNode *head) {
    if (head == NULL) return;

    ListNode *temp = head->next;

    while (temp != head) {
        ListNode *next = temp->next;
        free(temp);
        temp = next;
    }

    free(head);
}