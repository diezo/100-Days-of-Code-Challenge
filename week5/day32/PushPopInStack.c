// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 20 10

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_STACK_SIZE 8

typedef struct Stack {
    int *arr;
    int n;
    int size;
} Stack;

Stack *new_stack();
void stack_push(Stack*, int);
int stack_pop(Stack*, int*);
void freeStack(Stack*);

int main() {
    int n, m;

    scanf("%d", &n);

    Stack *stack = new_stack();

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        stack_push(stack, x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int x;
        if (!stack_pop(stack, &x)) puts("Couldn't pop element");
    }

    while (stack->n != 0) {
        int x;
        if (stack_pop(stack, &x)) printf("%d%s", x, (stack->n > 0) ? " " : "\n");
        else puts("Couldn't pop element");
    }

    freeStack(stack);

    return 0;
}

Stack *new_stack() {
    Stack *stack = malloc(sizeof(*stack));

    if (stack == NULL) {
        perror("Stack allocation failed");
        exit(EXIT_FAILURE);
    }

    stack->arr = malloc(sizeof(*(stack->arr)) * DEFAULT_STACK_SIZE);
    
    if (stack->arr == NULL) {
        free(stack);
        perror("Stack allocation failed");
        exit(EXIT_FAILURE);
    }

    stack->n = 0;
    stack->size = DEFAULT_STACK_SIZE;

    return stack;
}

void stack_push(Stack *stack, int val) {
    if (stack->n == stack->size) {
        void *ptr = realloc(stack->arr, sizeof(*(stack->arr)) * stack->size * 2);

        if (ptr == NULL) {
            perror("Failed to grow stack. Couldn't push element");
            return;
        }

        stack->arr = ptr;
        stack->size *= 2;
    }

    stack->arr[stack->n++] = val;
}

int stack_pop(Stack *stack, int *val) {
    if (stack->n == 0) return 0;

    *val = stack->arr[--stack->n];

    if (stack->size > DEFAULT_STACK_SIZE && stack->n < stack->size / 4) {
        int *ptr = realloc(stack->arr, sizeof(*(stack->arr)) * stack->size / 2);

        if (ptr == NULL) {
            perror("Failed to shrink stack");
            return 1;
        }

        stack->arr = ptr;
        stack->size /= 2;
    }

    return 1;
}

void freeStack(Stack *stack) {
    free(stack->arr);
    free(stack);
}