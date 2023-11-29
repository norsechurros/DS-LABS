#include <stdio.h>
#include <stdlib.h>
//merge sll
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* mergeLists(Node* list1, Node* list2) {
    Node* list3 = NULL;
    Node* current1 = list1;
    Node* current2 = list2;
    Node* current3 = NULL;

    while (current1 || current2) {
        if (current1) {
            Node* newNode1 = createNode(current1->data);
            if (list3 == NULL) {
                list3 = newNode1;
                current3 = list3;
            } else {
                current3->next = newNode1;
                current3 = current3->next;
            }
            current1 = current1->next;
        }
        if (current2) {
            Node* newNode2 = createNode(current2->data);
            if (list3 == NULL) {
                list3 = newNode2;
                current3 = list3;
            } else {
                current3->next = newNode2;
                current3 = current3->next;
            }
            current2 = current2->next;
        }
    }

    return list3;
}

void displayList(Node* list) {
    Node* current = list;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {

    Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);

    Node* list2 = createNode(10);
    list2->next = createNode(20);

    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    Node* mergedList = mergeLists(list1, list2);
    printf("Merged List: ");
    displayList(mergedList);



    return 0;
}

