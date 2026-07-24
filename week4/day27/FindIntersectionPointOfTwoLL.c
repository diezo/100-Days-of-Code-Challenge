// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

void freeList(ListNode*);

int main() {
    int n, m;

    ListNode *head1 = NULL;
    ListNode *tail1 = NULL;

    ListNode *head2 = NULL;
    ListNode *tail2 = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ListNode *node = malloc(sizeof(*node));
        scanf("%d", &node->val);
        node->next = NULL;

        if (head1 == NULL) head1 = tail1 = node;
        else {
            tail1->next = node;
            tail1 = node;
        }
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        ListNode *node = malloc(sizeof(*node));
        scanf("%d", &node->val);
        node->next = NULL;

        if (head2 == NULL) head2 = tail2 = node;
        else {
            tail2->next = node;
            tail2 = node;
        }
    }

    ListNode *i = head1;
    ListNode *j = head2;

    // Skip extra nodes
    for (int x = 0; x < abs(n - m); x++) {
        if (n > m) i = i->next;
        else j = j->next;
    }

    while ((i != NULL) && (j != NULL) && (i->val != j->val)) {
        i = i->next;
        j = j->next;
    }

    if (i != NULL) printf("%d\n", i->val);
    else puts("No Intersection");

    freeList(head1);
    freeList(head2);

    return 0;
}

void freeList(ListNode *head) {
    if (head == NULL) return;

    freeList(head->next);
    free(head);
}