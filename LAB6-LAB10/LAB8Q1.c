
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data);
Node* insertRear(Node* head, int data);
Node* deleteRear(Node* head);
Node* insertAtPosition(Node* head, int data, int position);
Node* deleteAtPosition(Node* head, int position);
Node* insertAfter(Node* head, int data, int key);
Node* insertBefore(Node* head, int data, int key);
void display(Node* head);
Node* reverse(Node* head);

int main() {
    Node* head = NULL;
    int choice, data, position, key;

    while (1) {
        printf("\n 1. Insert an element at the rear end\n");
        printf("2. Delete an element from the rear end\n");
        printf("3. Insert an element at a given position\n");
        printf("4. Delete an element from a given position\n");
        printf("5. Insert an element after another element\n");
        printf("6. Insert an element before another element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the rear end: ");
                scanf("%d", &data);
                head = insertRear(head, data);
                break;
            case 2:
                head = deleteRear(head);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 5:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &key);
                head = insertAfter(head, data, key);
                break;
            case 6:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &key);
                head = insertBefore(head, data, key);
                break;
            case 7:
                display(head);
                break;
            case 8:
                head = reverse(head);
                break;
            case 9:
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
    newNode->prev = newNode->next = NULL;
    return newNode;
}

Node* insertRear(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    return head;
}

Node* deleteRear(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}

Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    if (position <= 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }
    Node* current = head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of range. Element not inserted.\n");
        free(newNode);
        return head;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    return head;
}

Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (position <= 1) {
        Node* newHead = head->next;
        newHead->prev = NULL;
        free(head);
        return newHead;
    }
    Node* current = head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of range. Element not deleted.\n");
        return head;
    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}

Node* insertAfter(Node* head, int data, int key) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        printf("List is empty \n");
        free(newNode);
        return head;
    }
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return head;
        }
        current = current->next;
    }
    printf("Element not found. Element not inserted.\n");
    free(newNode);
    return head;
}

Node* insertBefore(Node* head, int data, int key) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        printf("List is empty. \n");
        free(newNode);
        return head;
    }
    if (head->data == key) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            return head;
        }
        current = current->next;
    }
    printf("Element not found. Element not inserted.\n");
    free(newNode);
    return head;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    printf("Doubly linked list elements (forward): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    printf("\n");
}

Node* reverse(Node* head) {
    Node* temp = NULL;
    Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}
