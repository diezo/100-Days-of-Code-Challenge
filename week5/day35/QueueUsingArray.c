// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

typedef struct Queue {
    ListNode *head;
    ListNode *tail;
} Queue;

Queue *new_queue();
void enqueue(Queue*, int);
bool dequeue(Queue*, int*);
bool peek(Queue*, int*);
bool is_empty(Queue*);
void free_queue(Queue*);

int main() {
    int n;

    Queue *queue = new_queue();

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(queue, val);
    }

    while (!is_empty(queue)) {
        int x;
        dequeue(queue, &x);
        printf("%d ", x);
    }
    puts("");

    free_queue(queue);

    return 0;
}

Queue *new_queue() {
    Queue *queue = malloc(sizeof(*queue));

    if (queue == NULL) {
        perror("Queue allocation failed");
        exit(1);
    }

    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

void enqueue(Queue *queue, int val) {
    ListNode *node = malloc(sizeof(*node));
    
    if (node == NULL) {
        perror("Queue node allocation failed");
        exit(1);
    }

    node->val = val;
    node->next = NULL;

    if (queue->head == NULL) {
        queue->head = queue->tail = node;
    }
    else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

bool dequeue(Queue *queue, int *val) {
    if (queue->head == NULL) return false;

    *val = queue->head->val;

    ListNode *temp = queue->head;
    queue->head = queue->head->next;
    
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(temp);
    return true;
}

bool peek(Queue *queue, int *val) {
    if (queue->head == NULL) return false;
    
    *val = queue->head->val;
    return true;
}

bool is_empty(Queue *queue) {
    return queue->head == NULL;
}

void free_queue(Queue *queue) {
    while (!is_empty(queue)) {
        int val;
        dequeue(queue, &val);
    }

    free(queue);
}