#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int ar[SIZE];
int top1 = -1;
int top2 = SIZE;

// Functions to push data
void push_stack1(int data) {
    if (top1 < top2 - 1) {
        ar[++top1] = data;
        printf("%d is pushed to Stack 1\n", data);
    } else {
        printf("Stack 1 is Full! Cannot Push\n");
    }
}

void push_stack2(int data) {
    if (top1 < top2 - 1) {
        ar[--top2] = data;
        printf("%d is pushed to Stack 2\n", data);
    } else {
        printf("Stack 2 is Full! Cannot Push\n");
    }
}

// Functions to pop data
int pop_stack1() {
    if (top1 >= 0) {
        int popped_value = ar[top1--];
        printf("%d is popped from Stack 1\n", popped_value);
        return popped_value;
    } else {
        printf("Stack 1 is Empty! Cannot Pop\n");
        return -1; // Indicate error with a negative value
    }
}

int pop_stack2() {
    if (top2 < SIZE) {
        int popped_value = ar[top2++];
        printf("%d is popped from Stack 2\n", popped_value);
        return popped_value;
    } else {
        printf("Stack 2 is Empty! Cannot Pop\n");
        return -1; // Indicate error with a negative value
    }
}

// Function to print Stack 1
void print_stack1() {
    int i;
    for (i = top1; i >= 0; --i) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

// Function to print Stack 2
void print_stack2() {
    int i;
    for (i = top2; i < SIZE; ++i) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int main6() {
    int choice, value;

    printf("We can push a total of 10 values\n");

    do {
        printf("\nMenu:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Print Stack 1\n");
        printf("6. Print Stack 2\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to Stack 1: ");
                scanf("%d", &value);
                push_stack1(value);
                break;
            case 2:
                printf("Enter value to push to Stack 2: ");
                scanf("%d", &value);
                push_stack2(value);
                break;
            case 3:
                pop_stack1();
                break;
            case 4:
                pop_stack2();
                break;
            case 5:
                printf("Stack 1: ");
                print_stack1();
                break;
            case 6:
                printf("Stack 2: ");
                print_stack2();
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
