
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        struct Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
    return head;
}

struct Node* deleteElement(struct Node* head, int key) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    struct Node* current = head;
    struct Node* toDelete = NULL;

    do {
        if (current->data == key) {
            toDelete = current;
            break;
        }
        current = current->next;
    } while (current != head);

    if (toDelete == NULL) {
        printf("Element %d not found in the list.\n", key);
        return head;
    }

    if (head->next == head) {
        // Only one element in the list
        free(toDelete);
        head = NULL;
    } else {
        struct Node* prevNode = toDelete->prev;
        struct Node* nextNode = toDelete->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        if (toDelete == head) {
            head = nextNode;
        }
        free(toDelete);
    }

    printf("Element %d deleted from the list.\n", key);
    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf(" (Circular)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
        printf("\nCircular Doubly Linked List Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                head = insertEnd(head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &key);
                head = deleteElement(head, key);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
