#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int q[SIZE];
int f = -1, r = -1;

void enqueue(int x) {
    if (r == SIZE - 1) {
        printf("Queue is full!\n");
    } else {
        if (f == -1) f = 0;
        q[++r] = x;
        printf("%d enqueued.\n", x);
    }
}

void dequeue() {
    if (f == -1 || f > r) {
        printf("Queue is empty!\n");
    } else {
        printf("%d dequeued.\n", q[f++]);
        if (f > r) f = r = -1;
    }
}

void display() {
    if (f == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = f; i <= r; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
}

int main() {
    int ch, val;
    while (1) {
        printf("\n1-Enqueue  2-Dequeue  3-Display  4-Quit\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
        } else if (ch == 2) {
            dequeue();
        } else if (ch == 3) {
            display();
        } else if (ch == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

