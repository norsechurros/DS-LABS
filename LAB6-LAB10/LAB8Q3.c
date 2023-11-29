#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* concatenateLists(Node* X1, Node* X2) {
    if (X1 == NULL) {
        return X2;
    }
    if (X2 == NULL) {
        return X1;
    }

    Node* currentX1 = X1;
    while (currentX1->next != NULL) {
        currentX1 = currentX1->next;
    }

    currentX1->next = X2;
    X2->prev = currentX1;

    return X1;
}

void displayList(Node* list) {
    Node* current = list;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* X1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    X1->next = node2;
    node2->prev = X1;
    node2->next = node3;
    node3->prev = node2;

    Node* X2 = createNode(4);
    Node* node5 = createNode(5);
    X2->next = node5;
    node5->prev = X2;

    // Concatenate X2 to X1
    X1 = concatenateLists(X1, X2);

    printf("Concatenated List (X1): ");
    displayList(X1);

    // Free dynamically allocated memory
    while (X1 != NULL) {
        Node* temp = X1;
        X1 = X1->next;
        free(temp);
    }

    return 0;
}
