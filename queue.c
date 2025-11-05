#include <stdio.h>
#include <stdlib.h>
#define N 10

int queue[N];
int rear = -1, front = -1;

void enqueue() {
    int val;
    printf("Enter the data: ");
    scanf("%d", &val);
    if (rear == N - 1) {
        printf("Queue overflow\n");
        return;
    } else if (rear == -1 && front == -1) {
        rear = front = 0;
        queue[rear] = val;
    } else {
        rear++;
        queue[rear] = val;
    }
}

void dequeue() {
    if (rear == -1 && front == -1) {
        printf("Queue underflow\n");
        return;
    } else if (rear == front) {
        printf("Deleted element is %d\n", queue[front]);
        rear = front = -1;
    } else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}

void display() {
    int i;
    if (rear == -1 && front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int opt;
    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter the option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    } while (1);
}

    
      
      
     
     


