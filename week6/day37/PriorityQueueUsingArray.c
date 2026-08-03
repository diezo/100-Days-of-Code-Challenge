// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PQ_CAPACITY 100

typedef struct PriorityQueue {
    int *arr;
    int size;
} PriorityQueue;

PriorityQueue *new_pq();
void pq_enqueue(PriorityQueue*, int);
int pq_dequeue(PriorityQueue*);
int pq_peek(PriorityQueue*);
void free_pq(PriorityQueue*);

int main() {
    int n;
    scanf("%d", &n);

    PriorityQueue *pq = new_pq();

    for (int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", &op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            pq_enqueue(pq, x);

        } else if (strcmp(op, "delete") == 0) {
            int val = pq_dequeue(pq);
            printf("%d\n", val);

        } else if (strcmp(op, "peek") == 0) {
            int val = pq_peek(pq);
            printf("%d\n", val);
        }
    }

    free_pq(pq);

    return 0;
}

PriorityQueue *new_pq() {
    PriorityQueue *pq = malloc(sizeof(*pq));

    if (pq == NULL) {
        perror("Priority queue allocation failed");
        exit(1);
    }

    int *ptr = malloc(sizeof(*ptr) * PQ_CAPACITY);

    if (ptr == NULL) {
        free(pq);
        perror("Priority queue array allocation failed");
        exit(1);
    }

    pq->arr = ptr;
    pq->size = 0;

    return pq;
}

void pq_enqueue(PriorityQueue *pq, int val) {
    if (pq->size == PQ_CAPACITY) {
        puts("Priority queue is full");
        return;
    }

    int idx = pq->size;

    for (int i = 0; i < pq->size; i++) {
        if (val < pq->arr[i]) {
            idx = i;
            break;
        }
    }

    for (int i = pq->size - 1; i >= idx; i--) {
        pq->arr[i + 1] = pq->arr[i];
    }

    pq->arr[idx] = val;
    pq->size++;
}

int pq_dequeue(PriorityQueue *pq) {
    if (pq->size == 0) return -1;
    
    int temp = pq->arr[0];

    for (int i = 1; i < pq->size; i++) {
        pq->arr[i - 1] = pq->arr[i];
    }

    pq->size--;
    return temp;
}

int pq_peek(PriorityQueue *pq) {
    if (pq->size == 0) return -1;
    return pq->arr[0];
}

void free_pq(PriorityQueue *pq) {
    free(pq->arr);
    free(pq);
}