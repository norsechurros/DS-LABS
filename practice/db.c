#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

// Push a character onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

// Pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

// Check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

// Reverse a string
void strrev(char str[]) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack operatorStack;
    initStack(&operatorStack);

    int i = 0, j = 0;
    int len = strlen(infix);
    infix[len - 1] = '\0'; // Remove the newline character from fgets input

    // Reverse the infix expression
    strrev(infix);

    while (infix[i] != '\0') {
        if (infix[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(infix[i]) || isalpha(infix[i])) {
            // If it's an operand, add it to the postfix expression
            postfix[j++] = infix[i];
        } else if (infix[i] == ')') {
            // If it's a closing parenthesis, push it onto the stack
            push(&operatorStack, infix[i]);
        } else if (infix[i] == '(') {
            // If it's an opening parenthesis, pop and add operators from the stack
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != ')') {
                postfix[j++] = pop(&operatorStack);
            }
            if (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] == ')') {
                pop(&operatorStack); // Pop the closing parenthesis
            }
        } else if (isOperator(infix[i])) {
            // If it's an operator, pop and add operators from the stack
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != ')' &&
                   getPrecedence(operatorStack.items[operatorStack.top]) >= getPrecedence(infix[i])) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, infix[i]);
        }
        i++;
    }

    // Pop any remaining operators from the stack and add to the postfix expression
    while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != ')') {
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(infix, postfix);

    // Reverse the postfix expression to get the prefix expression
    strrev(postfix);

    printf("Prefix expression: %s\n", postfix);

    return 0;
}
