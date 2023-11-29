#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

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

void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    initializeStack(&stack);
    int length = strlen(infix);
    int j = 0;

    for (int i = length - 1; i >= 0; i--) {
        char ch = infix[i];
        if (isOperator(ch)) {
            while (!isEmpty(&stack) && stack.data[stack.top] != ')' &&
                   isOperator(stack.data[stack.top]) &&
                   (ch != '^' || stack.data[stack.top] != '^') &&
                   (ch != '*' || stack.data[stack.top] != '*' || stack.data[stack.top] != '/') &&
                   (ch != '+' || stack.data[stack.top] != '+' || stack.data[stack.top] != '-')) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        } else if (ch == ')') {
            push(&stack, ch);
        } else if (ch == '(') {
            while (!isEmpty(&stack) && stack.data[stack.top] != ')') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop the ')'
        } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            postfix[j++] = ch;
        }
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
    strrev(postfix);
}

int evaluatePostfixExpression(char postfix[]) {
    Stack stack;
    initializeStack(&stack);
    int length = strlen(postfix);

    for (int i = 0; i < length; i++) {
        char ch = postfix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            printf("Enter value for variable '%c': ", ch);
            int value;
            scanf("%d", &value);
            push(&stack, value);
        } else if (isOperator(ch)) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (ch) {
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
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter a prefix expression with variables: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    int result = evaluatePostfixExpression(postfix);

    printf("Result: %d\n", result);
    return 0;
}
