// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression

// Example:
// Input:
// A+B*C

// Output:
// ABC*+

// Explanation:
// Operator precedence: * > +
// Use stack to handle operator precedence and associativity

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_STACK_SIZE 8

typedef struct Stack {
    int *arr;
    int n;
    int size;
} Stack;

void evaluate(char, Stack*);
int isOperator(char);
int precedence(char);

Stack *new_stack();
void stack_push(Stack*, int);
int stack_peek(Stack*, int*);
int stack_pop(Stack*, int*);
void freeStack(Stack*);

int main() {
    char expression[100];

    Stack *stack = new_stack();

    scanf("%s", &expression);

    int i = 0;
    while (expression[i] != '\0') {
        char c = expression[i++];
        evaluate(c, stack);
    }

    int val;
    while (stack_pop(stack, &val)) {
        printf("%c", val);
    }

    puts("");

    freeStack(stack);

    return 0;
}

void evaluate(char c, Stack *stack) {
    if (!isOperator(c)) {
        printf("%c", c);
        return;
    }

    int val;
    while (stack_peek(stack, &val) && precedence(val) >= precedence(c)) {
        stack_pop(stack, &val);
        printf("%c", val);
    }

    stack_push(stack, c);
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return -1;
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

int stack_peek(Stack *stack, int *val) {
    if (stack->n == 0) return 0;
    
    *val = stack->arr[stack->n - 1];
    return 1;
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