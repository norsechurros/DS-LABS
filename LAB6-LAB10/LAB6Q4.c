#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
//prefix to postfix

struct Stack {
    char data[MAX_SIZE][MAX_SIZE];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

void push(struct Stack *stack, char value[]) {
    if (stack->top < MAX_SIZE - 1) {
        stack->top++;
        strcpy(stack->data[stack->top], value);
    } else {
        printf("Stack Overflow\n");
        exit(1);
    }
}

void pop(struct Stack *stack, char value[]) {
    if (!isEmpty(stack)) {
        strcpy(value, stack->data[stack->top]);
        stack->top--;
    } else {
        printf("Stack Underflow\n");
        exit(1);
    }
}

int isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return 1;
    }
    return 0;
}


void preToPost(char pre_exp[], char postfix[]) {
    struct Stack stack;
    initializeStack(&stack);

    int length = strlen(pre_exp);
    char op1[MAX_SIZE], op2[MAX_SIZE];

    for (int i = length - 1; i >= 0; i--) {
        if (pre_exp[i] == ' ')
            continue;

        if (isOperator(pre_exp[i])) {
            pop(&stack, op1);
            pop(&stack, op2);

            sprintf(postfix, "%s%s%c", op1, op2, pre_exp[i]);

            push(&stack, postfix);
        } else {
            char operand[2];
            operand[0] = pre_exp[i];
            operand[1] = '\0';
            push(&stack, operand);
        }
    }

    pop(&stack, postfix);
}

int main() {
    char pre_exp[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter a prefix expression: ");
    gets(pre_exp);

    preToPost(pre_exp, postfix);

    printf("Postfix: %s\n", postfix);

    return 0;
}
