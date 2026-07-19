// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 30

// Output:
// 10 20 40 50

// Explanation:
// Traverse list, find first node with key, remove it by adjusting previous node's next pointer.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *removeKey(ListNode*, int);
void freeList(ListNode*);

int main() {
    int n;

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

    int k;
    scanf("%d", &k);

    ListNode *newHead = removeKey(head, k);

    ListNode *temp = newHead;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    puts("");

    freeList(newHead);

    return 0;
}

ListNode *removeKey(ListNode *head, int k) {
    ListNode *i = NULL;
    ListNode *j = head;

    while (j != NULL) {
        if (j->val == k) {
            if (i == NULL) head = j->next;
            else i->next = j->next;

            free(j);

            return head;
        }

        i = j;
        j = j->next;
    }

    return head;
}

void freeList(ListNode *head) {
    if (head == NULL) return;

    freeList(head->next);
    free(head);
}