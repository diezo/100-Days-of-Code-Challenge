// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

// Example:
// Input:
// 6
// 10 20 30 20 40 20
// 20

// Output:
// 3

// Explanation:
// Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

int countOccurrences(ListNode*, int);
void freeList(ListNode*);

int main() {
    int n, k;

    scanf("%d", &n);

    ListNode *head = NULL;
    ListNode *tail = NULL;

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

    int count = countOccurrences(head, k);

    printf("%d\n", count);

    freeList(head);

    return 0;
}

int countOccurrences(ListNode *head, int k) {
    int count = 0;

    while (head != NULL) {
        if (head->val == k) count++;
        head = head->next;
    }

    return count;
}

void freeList(ListNode *head) {
    if (head == NULL) return;

    freeList(head->next);
    free(head);
}