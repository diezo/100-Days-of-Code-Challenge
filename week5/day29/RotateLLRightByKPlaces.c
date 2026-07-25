// Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

void freeList(ListNode*);

int main() {
    int n, k;

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

    scanf("%d", &k);

    if (tail == NULL) return 0;
    tail->next = head;

    k = k % n;

    for (int i = 0; i < (n - k - 1); i++) {
        head = head->next;
    }

    ListNode *newHead = head->next;

    if (k != 0) {
        head->next = NULL;
        head = newHead;
    } else {
        tail->next = NULL;
    }

    ListNode *temp = newHead;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    puts("");

    freeList(newHead);

    return 0;
}

void freeList(ListNode *head) {
    if (head == NULL) return;

    freeList(head->next);
    free(head);
}