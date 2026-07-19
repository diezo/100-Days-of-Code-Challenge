// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode *mergeLists(ListNode *head1, ListNode *head2);
void deleteList(ListNode *head);

int main() {
    int n, m;

    ListNode *head1 = NULL;
    ListNode *tail1 = NULL;

    ListNode *head2 = NULL;
    ListNode *tail2 = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ListNode *node = malloc(sizeof(ListNode));
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
        ListNode *node = malloc(sizeof(ListNode));
        scanf("%d", &node->val);
        node->next = NULL;

        if (head2 == NULL) head2 = tail2 = node;
        else {
            tail2->next = node;
            tail2 = node;
        }
    }

    ListNode *res = mergeLists(head1, head2);
    ListNode *temp = res;

    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    puts("");

    deleteList(head1);
    deleteList(head2);
    deleteList(res);

    return 0;
}

ListNode *mergeLists(ListNode *head1, ListNode *head2) {
    ListNode *newHead = NULL;
    ListNode *newTail = NULL;

    while (head1 != NULL && head2 != NULL) {
        ListNode *node = malloc(sizeof(ListNode));
        node->next = NULL;

        if (head1->val < head2->val) {
            node->val = head1->val;
            head1 = head1->next;
        } else {
            node->val = head2->val;
            head2 = head2->next;
        }

        if (newHead == NULL) newHead = newTail = node;
        else {
            newTail->next = node;
            newTail = node;
        }
    }

    while (head1 != NULL) {
        ListNode *node = malloc(sizeof(ListNode));
        node->val = head1->val;
        node->next = NULL;

        head1 = head1->next;

        if (newHead == NULL) newHead = newTail = node;
        else {
            newTail->next = node;
            newTail = node;
        }
    }

    while (head2 != NULL) {
        ListNode *node = malloc(sizeof(ListNode));
        node->val = head2->val;
        node->next = NULL;
        
        head2 = head2->next;

        if (newHead == NULL) newHead = newTail = node;
        else {
            newTail->next = node;
            newTail = node;
        }
    }

    return newHead;
}

void deleteList(ListNode *head) {
    if (head == NULL) return;

    if (head->next != NULL) {
        deleteList(head->next);
    }
    
    free(head);
}