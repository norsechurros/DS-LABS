#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

void push(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int evaluatePrefixExpression(char expression[]) {
    Stack stack;
    initializeStack(&stack);

    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--) {
        if (isalpha(expression[i])) {
            // Skip variables
            continue;
        } else if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == ' ' || expression[i] == '\t') {
            // Ignore spaces and tabs
            continue;
        } else if (isOperator(expression[i])) {
            if (isEmpty(&stack) || isEmpty(&stack)) {
                printf("Not enough operands for operator: %c\n", expression[i]);
                exit(1);
            }
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            char operator = expression[i];

            switch (operator) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                case '%':
                    if (operand2 == 0) {
                        printf("Modulo by zero is not allowed.\n");
                        exit(1);
                    }
                    push(&stack, operand1 % operand2);
                    break;
            }
        } else {
            printf("Invalid character in the expression: %c\n", expression[i]);
            exit(1);
        }
    }

    if (isEmpty(&stack) || stack.top > 0) {
        printf("Invalid expression.\n");
        exit(1);
    }

    return pop(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter a prefix expression: ");
    gets(expression);

    int result = evaluatePrefixExpression(expression);

    printf("Result: %d\n", result);
    return 0;
}
