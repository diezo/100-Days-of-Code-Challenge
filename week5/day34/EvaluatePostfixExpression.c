// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

typedef struct Stack {
    ListNode *head;
} Stack;

int evaluate(Stack*, char*);
bool isDigit(char);
bool isOperator(char);
Stack *new_stack();
void stack_push(Stack*, int);
bool stack_pop(Stack*, int*);
void free_stack(Stack*);

int main() {
    Stack *stack = new_stack();

    char expression[100];
    fgets(expression, sizeof(expression), stdin);

    int res = evaluate(stack, expression);
    printf("%d\n", res);

    free_stack(stack);

    return 0;
}

int evaluate(Stack *stack, char* expression) {
    int i = -1;

    int digit = 0;
    bool reading = false;

    while (expression[++i] != '\0') {
        char c = expression[i];

        if (!isDigit(c) && reading) {
            stack_push(stack, digit);
            digit = 0;
            reading = false;
        }

        if (c == ' ' || c == '\n') continue;

        if (!isOperator(c)) {
            reading = true;
            digit = (digit * 10) + (c - '0');
        } else {
            int a, b, res;

            if (!stack_pop(stack, &b) || !stack_pop(stack, &a)) {
                puts("Expression seems to be invalid");
                free_stack(stack);
                exit(1);
            }

            switch (c) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    res = a / b;
                    break;
            }

            stack_push(stack, res);
        }
    }

    if (reading) {
        stack_push(stack, digit);
    }

    int ans;

    if (!stack_pop(stack, &ans)) {
        puts("Expression seems to be invalid");
        free_stack(stack);
        exit(1);
    }

    return ans;
}

bool isDigit(char c) {
    int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 10; i++) {
        if (digits[i] == c - '0') return true;
    }

    return false;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Stack *new_stack() {
    Stack *stack = malloc(sizeof(*stack));

    if (stack == NULL) {
        perror("Stack allocation failed");
        exit(1);
    }

    stack->head = NULL;
    return stack;
}

void stack_push(Stack *stack, int val) {
    ListNode *node = malloc(sizeof(*node));

    if (node == NULL) {
        perror("Node allocation failed");
        exit(1);
    }

    node->val = val;
    node->next = stack->head;

    stack->head = node;
}

bool stack_pop(Stack *stack, int *val) {
    if (stack->head == NULL) return false;
    *val = stack->head->val;

    ListNode *temp = stack->head;
    stack->head = temp->next;
    free(temp);

    return true;
}

void free_stack(Stack *stack) {
    while (stack->head != NULL) {
        ListNode *temp = stack->head;
        stack->head = temp->next;
        free(temp);
    }

    free(stack);
}