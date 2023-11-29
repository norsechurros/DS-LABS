#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertBefore(struct Node* head, int element, int newData) {
    struct Node* newNode = createNode(newData);
    if (head == NULL) {
        printf("List is empty. Cannot insert before.\n");
        return head;
    }
    if (head->data == element) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != element) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Element not found in the list.\n");
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

struct Node* insertAfter(struct Node* head, int element, int newData) {
    struct Node* newNode = createNode(newData);
    if (head == NULL) {
        printf("List is empty\n");
        free(newNode);
        return head;
    }
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == element) {
            newNode->next = current->next;
            current->next = newNode;
            return head;
        }
        current = current->next;
    }
    printf("Element not found in the list.\n");
    free(newNode);
    return head;
}

struct Node* insertEnd(struct Node* head, int newData) {
    struct Node* newNode = createNode(newData);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* deleteElement(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Element not found in the list.\n");
    } else {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
    return head;
}

void traverseList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

struct Node* deleteAlternateNodes(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
    return head;
}

struct Node* insertSorted(struct Node* head, int newData) {
    struct Node* newNode = createNode(newData);
    if (head == NULL || head->data >= newData) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data < newData) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, element, newData;

    while (1) {
        printf("\nLinked List Menu:\n");
        printf("1. Insert before element\n");
        printf("2. Insert after element\n");
        printf("3. Insert at the end\n");
        printf("4. Delete element\n");
        printf("5. Traverse the list\n");
        printf("6. Reverse the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert in a sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element before which to insert: ");
                scanf("%d", &element);
                printf("Enter new data: ");
                scanf("%d", &newData);
                head = insertBefore(head, element, newData);
                break;

            case 2:
                printf("Enter element after which to insert: ");
                scanf("%d", &element);
                printf("Enter new data: ");
                scanf("%d", &newData);
                head = insertAfter(head, element, newData);
                break;

            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &newData);
                head = insertEnd(head, newData);
                break;

            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                head = deleteElement(head, element);
                break;

            case 5:
                traverseList(head);
                break;

            case 6:
                head = reverseList(head);
                break;

            case 7:
                head = deleteAlternateNodes(head);
                break;

            case 8:
                printf("Enter data to insert in a sorted manner: ");
                scanf("%d", &newData);
                head = insertSorted(head, newData);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
