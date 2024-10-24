#include <stdio.h>
#define SIZE 5 // Define the size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        return 1;
    }
    return 0;
}

// Check if the queue is empty
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0; // Circular increment
    } else {
        rear++;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Remove an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = queue[front];
    queue[front] = -1; // Optional: Mark the dequeued position as empty

    if (front == rear) { // Queue has only one element
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0; // Circular increment
    } else {
        front++;
    }

    printf("Removed %d\n", data);
    return data;
}

// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    return 0;
}

