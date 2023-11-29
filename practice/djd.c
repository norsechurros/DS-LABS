#include <stdio.h>

typedef struct Node
{
    int value
    struct Node* next;
}Node;

Node* head = NULL;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

void insert(int data)
{
    Node* newNode = createNode(data);

    if(head == NULL)
    {
        head = newNode;
    }

    else{
        Node* current = head;
        while(current->next != NULL)
        {
            current = current->next;

        }

        current->next = newNode;
    }


    void delete(int data)
    {
        if(head == NULL)
        {
            printf("List empty: \n");
            return;

        }

        Node* current = head;
        Node* prev = NULL;

        while(current!=NULL && current->value !=data)
        {
            prev = current;
            current = current-> next;
        }

        if(current == NULL)
        {
            printf("Element not found: \n");
            return;
        }

        if (prev == NULL)
        {
            head = current->next;
        }

        else
        {
            prev->next = current->next;
        }

        free(current);
        printf("Element deleted: ")
    }
