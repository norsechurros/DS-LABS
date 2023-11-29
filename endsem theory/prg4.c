#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the circular singly linked list
void insert(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node as the head
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to reverse the circular singly linked list
void reverse(struct Node** head) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    do {
        // Update the next pointer
        next = current->next;

        // Reverse the link of the current node
        current->next = prev;

        // Move the prev and current pointers
        prev = current;
        current = next;
    } while (current != *head);

    // Update the head pointer to point to the last node
    *head = prev;
}

// Function to display the circular singly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular singly linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Original list: ");
    display(head);

    // Reverse the circular singly linked list
    reverse(&head);

    printf("Reversed list: ");
    display(head);

    return 0;
}
