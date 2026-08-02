// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_CAPACITY 100

typedef struct Queue {
    int *arr;
    int front;
    int rear;
} Queue;

Queue *new_queue();
void enqueue(Queue*, int);
bool dequeue(Queue*, int*);
bool is_empty(Queue*);
bool is_full(Queue*);
void free_queue(Queue*);

int main() {
    int n;
    scanf("%d", &n);

    Queue *queue = new_queue();

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(queue, x);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int x;
        dequeue(queue, &x);
    }

    while (!is_empty(queue)) {
        int x;
        dequeue(queue, &x);
        printf("%d ", x);
    }

    free_queue(queue);

    return 0;
}

Queue *new_queue() {
    Queue *queue = malloc(sizeof(*queue));

    if (queue == NULL) {
        perror("Queue allocation failed");
        exit(1);
    }

    queue->arr = malloc(sizeof(*(queue->arr)) * QUEUE_CAPACITY);

    if (queue->arr == NULL) {
        free(queue);
        perror("Queue array allocation failed");
        exit(1);
    }

    queue->front = 0;
    queue->rear = 0;

    return queue;
}

void enqueue(Queue *queue, int val) {
    if (is_full(queue)) {
        puts("Queue is full");
        return;
    }

    queue->arr[queue->rear] = val;
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
}

bool dequeue(Queue *queue, int *ptr) {
    if (is_empty(queue)) return false;

    *ptr = queue->arr[queue->front];
    queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    
    return true;
}

bool is_empty(Queue *queue) {
    return queue->front == queue->rear;
}

bool is_full(Queue *queue) {
    return (queue->rear + 1) % QUEUE_CAPACITY == queue->front;
}

void free_queue(Queue *queue) {
    free(queue->arr);
    free(queue);
}