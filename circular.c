#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int rear = -1, front = -1;

void enqueue() {
    int val;
    printf("Enter the data: ");
    scanf("%d", &val);

    if ((rear == -1 && front == -1)) {
        rear = front = 0;
        queue[rear] = val;
    } 
    else if ((rear + 1) % N == front) {
        printf("Queue Overflow\n");
    } 
    else {
        rear = (rear + 1) % N;
        queue[rear] = val;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue Underflow\n");
    } 
    else if (front == rear) {
        printf("Deleted element: %d\n", queue[front]);
        front = rear = -1;
    } 
    else {
        printf("Deleted element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } 
    else {
        int i = front;
        printf("Queue elements: ");
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % N;
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

