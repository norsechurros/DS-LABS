#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

bool isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", data);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = data;
    printf("%d enqueued to the queue\n", data);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display();

    printf("Dequeued element: %d\n", dequeue());

    enqueue(6);
    enqueue(7);

    display();

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    display();

    return 0;
}
