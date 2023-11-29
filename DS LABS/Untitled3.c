#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Stack to store operators
char stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

// Function to pop an element from the stack
char pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to check if a character is an operator (+, -, *, /)
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert postfix expression to infix expression
void postfixToInfix(char postfix[]) {
    char infix[MAX_SIZE];
    int length = strlen(postfix);
    int infixIndex = 0;

    for (int i = 0; i < length; i++) {
        char currentChar = postfix[i];

        if (isOperator(currentChar)) {
            char operand2 = pop();
            char operand1 = pop();

            // Construct the infix expression for the current operator
            infix[infixIndex++] = '(';
            infix[infixIndex++] = operand1;
            infix[infixIndex++] = currentChar;
            infix[infixIndex++] = operand2;
            infix[infixIndex++] = ')';
        } else {
            // Operand, push onto the stack as is
            push(currentChar);
        }
    }

    // Null-terminate the infix expression
    infix[infixIndex] = '\0';

    // Print the final infix expression
    printf("Infix expression: %s\n", infix);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    postfixToInfix(postfix);

    return 0;
}
