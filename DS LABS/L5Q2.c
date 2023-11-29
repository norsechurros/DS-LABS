
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int items[MAX_SIZE];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

void push(struct Stack *stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initialize(&stack);

    int i = 0;

    while (postfix[i] != '\0') {
        char token = postfix[i];

        if (isdigit(token)) {
            push(&stack, token - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (token) {
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
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid postfix expression\n");
                    exit(1);
            }
        }

        i++;
    }

    if (!isEmpty(&stack)) {
        return pop(&stack);
    } else {
        printf("Invalid postfix expression\n");
        exit(1);
    }
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
