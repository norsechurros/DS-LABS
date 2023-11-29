#include <stdio.h>
#include <stdlib.h>
//stack using SLL
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
Node* push(Node* top, int data);
Node* pop(Node* top);
void display(Node* top);

int main() {
    Node* top = NULL;
    int choice, data;

    while (1) {
        printf("\n 1. Push an element\n");
        printf("2. Pop an element\n");
        printf("3. Display the stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &data);
                top = push(top, data);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* push(Node* top, int data) {
    Node* newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return top;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
    printf("Element popped successfully.\n");
    return top;
}

void display(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node* current = top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
