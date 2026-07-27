// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'

// Example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 3

// Output:
// 20 10
// 20
// 10

#include <stdio.h>
#include <stdlib.h>

#define STACK_DEFAULT_SIZE 8

typedef struct Stack {
    int *arr;
    int size, n;
} Stack;

Stack *new_stack();
void stack_push(Stack*, int);
int stack_pop(Stack*, int*);
void stack_display(Stack*);

int main() {
    int n;
    Stack *stack = new_stack();

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int val;

            scanf("%d", &val);
            stack_push(stack, val);

        } else if (op == 2) {
            int val;
            
            if (stack_pop(stack, &val)) printf("%d\n", val);
            else puts("Stack Underflow");

        } else if (op == 3) {
            stack_display(stack);
        }
    }

    free(stack->arr);
    free(stack);

    return 0;
}

Stack *new_stack() {
    Stack *stack = malloc(sizeof(*stack));

    if (stack == NULL) {
        perror("Stack allocation failed!");
        exit(1);
    }

    stack->arr = malloc(sizeof(*(stack->arr)) * STACK_DEFAULT_SIZE);

    if (stack->arr == NULL) {
        perror("Stack allocation failed!");
        exit(1);
    }

    stack->size = STACK_DEFAULT_SIZE;
    stack->n = 0;

    return stack;
}

void stack_push(Stack *stack, int val) {
    if (stack->size == stack->n) {
        stack->size = stack->size * 2;
        int *ptr = realloc(stack->arr, sizeof(*(stack->arr)) * stack->size);

        if (ptr == NULL) {
            perror("Failed to grow stack!");
            stack->size = stack->size / 2;
            return;
        }

        stack->arr = ptr;
    }

    (stack->arr)[(stack->n)++] = val;
}

int stack_pop(Stack *stack, int *val) {
    if (stack->n == 0) return 0;

    *val = (stack->arr)[--(stack->n)];

    if (stack->size > STACK_DEFAULT_SIZE && stack->n <= (stack->size / 4)) {
        stack->size = stack->size / 2;
        int *ptr = realloc(stack->arr, sizeof(*(stack->arr)) * stack->size);

        if (ptr == NULL) {
            perror("Failed to shrink stack!");
            stack->size = stack->size * 2;
            return 1;
        }

        stack->arr = ptr;
    }

    return 1;
}

void stack_display(Stack *stack) {
    for (int i = (stack->n) - 1; i >= 0; i--) {
        printf("%d%s", (stack->arr)[i], (i == 0) ? "" : " ");
    }
    
    puts("");
}