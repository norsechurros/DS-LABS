#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Initialize an empty stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

// Get the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '^') return 3;
    else if (operator == '*' || operator == '/') return 2;
    else if (operator == '+' || operator == '-') return 1;
    return 0; // Lower precedence for other characters
}

// Convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack operatorStack;
    initStack(&operatorStack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&operatorStack, token);
        } else if (token == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            if (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] == '(') {
                pop(&operatorStack); // Pop '(' from the stack
            } else {
                printf("Invalid expression: Mismatched parentheses\n");
                exit(1);
            }
        } else { // Operator
            while (!isEmpty(&operatorStack) && getPrecedence(operatorStack.items[operatorStack.top]) >= getPrecedence(token)) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, token);
        }

        i++;
    }

    // Pop any remaining operators from the stack
    while (!isEmpty(&operatorStack)) {
        char op = pop(&operatorStack);
        if (op == '(') {
            printf("Invalid expression: Mismatched parentheses\n");
            exit(1);
        }
        postfix[j++] = op;
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

