#include <stdio.h>
#include <stdlib.h>
// union and intersection
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

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* unionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    while (list1 != NULL) {
        insertEnd(&result, list1->data);
        list1 = list1->next;
    }
    while (list2 != NULL) {
        if (!search(result, list2->data)) {
            insertEnd(&result, list2->data);
        }
        list2 = list2->next;
    }
    return result;
}

struct Node* intersectionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    while (list1 != NULL) {
        if (search(list2, list1->data)) {
            insertEnd(&result, list1->data);
        }
        list1 = list1->next;
    }
    return result;
}

int search(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

struct Node* acceptList() {
    struct Node* head = NULL;
    int n, data;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&head, data);
    }
    return head;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    printf("Enter elements for the first list:\n");
    list1 = acceptList();

    printf("Enter elements for the second list:\n");
    list2 = acceptList();

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node* unionResult = unionLists(list1, list2);
    struct Node* intersectionResult = intersectionLists(list1, list2);

    printf("Union of lists: ");
    printList(unionResult);

    printf("Intersection of lists: ");
    printList(intersectionResult);

    return 0;
}
