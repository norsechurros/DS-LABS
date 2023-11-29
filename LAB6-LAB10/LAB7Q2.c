#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;

struct Node {
    int data;
    struct Node* next;
};

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node* head = NULL;

void createList(int num) {
    int ele;
    if (num == 0)
        return;
    else {
        printf("Enter element to be inserted: ");
        scanf("%d", &ele);

        node* newNode = createNode(ele);
        if (head == NULL) {
            head = newNode;
        } else {
            node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
        createList(num - 1);
    }
}

void Traverse(node* current) {
    if (current == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", current->data);
    Traverse(current->next);
}

int main() {
    int num;

    printf("Enter the number of elements to create a list: ");
    scanf("%d", &num);

    createList(num);

    printf("List contents: ");
    Traverse(head);

    return 0;
}
