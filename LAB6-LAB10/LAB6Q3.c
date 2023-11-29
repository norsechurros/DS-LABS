
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
//prefix to infix
typedef struct Stack {
    char data[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

void push(Stack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void prefixToInfix(char expression[]) {
    Stack stack;
    initializeStack(&stack);

    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--) {
        char ch = expression[i];

        if (isspace(ch)) {
            // Skip spaces and continue to the next character.
            continue;
        }

        if (isOperator(ch)) {
            char operand1[100], operand2[100];
            if (!isEmpty(&stack)) {
                strcpy(operand1, pop(&stack));
            } else {
                printf("Invalid prefix expression\n");
                exit(1);
            }
            if (!isEmpty(&stack)) {
                strcpy(operand2, pop(&stack));
            } else {
                printf("Invalid prefix expression\n");
                exit(1);
            }
            char infix[100];
            sprintf(infix, "(%s %c %s)", operand1, ch, operand2);
            push(&stack, infix);
        } else {
            char operand[2];
            operand[0] = ch;
            operand[1] = '\0';
            push(&stack, operand);
        }
    }

    if (!isEmpty(&stack) && stack.top == 0) {
        printf("Infix Expression: %s\n", stack.data[0]);
    } else {
        printf("Invalid prefix expression\n");
        exit(1);
    }
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter a prefix expression: ");
    gets(expression);

    prefixToInfix(expression);

    return 0;
}
