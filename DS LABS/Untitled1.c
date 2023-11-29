#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int row, col, value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
Node* insertAtEnd(Node* head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    if (head == NULL) {
        return newNode; // Return the new node as the new head
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head; // Return the original head
    }
}

int main() {
    int M, N;
    printf("Enter the number of rows (M) and columns (N): ");
    scanf("%d %d", &M, &N);

    int MAT[M][N];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &MAT[i][j]);
        }
    }

    Node* head = NULL;

    // Convert the 2D sparse matrix to a linked list
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (MAT[i][j] != 0) {
                head = insertAtEnd(head, i, j, MAT[i][j]);
            }
        }
    }

    // Display the linked list in row-major order
    Node* current = head;
    printf("Sparse matrix in row-major order:\n");
    while (current != NULL) {
        printf("<%d, %d, %d> ", current->row, current->col, current->value);
        current = current->next;
    }
    printf("\n");

    // Free the memory allocated for the linked list
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

