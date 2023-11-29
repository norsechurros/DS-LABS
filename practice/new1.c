#include <stdio.h>
#define maxs 10

int queue[maxs];
int front = -1, rear = -1;

int isFull() {
    if ((rear + 1) % maxs == front)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (rear == -1 && front == -1) // Corrected the condition
        return 1;
    else
        return 0;
}

void display() {
    printf("The elements are: \n");
    if (isEmpty()) { // Added parentheses for function call
        printf("List is empty.\n");
    } else {
        for (int i = front; i != (rear + 1) % maxs; i = (i + 1) % maxs) { // Corrected the loop condition
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % maxs;
    }

    queue[rear] = data;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % maxs;
    }
}

int main() {
    int ch, data, flag = 1;
    while (flag) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter element to be enqueued: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            printf("Element dequeued, remaining elements are:\n");
            display();
            break;

        case 3:
            printf("Elements are:\n");
            display();
            break;

        default:
            flag = 0;
            break;
        }
    }

    return 0;
}
