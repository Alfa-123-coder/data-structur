#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int q[SIZE], f = -1, r = -1;

void enqueue(int x) {
    if (r == SIZE - 1) printf("Full\n");
    else {
        if (f == -1) f = 0;
        q[++r] = x;
    }
}

void dequeue() {
    if (f == -1 || f > r) printf("Empty\n");
    else {
        printf("Dequeued: %d\n", q[f++]);
        if (f > r) f = r = -1;
    }
}

void display() {
    if (f == -1) printf("Empty\n");
    else {
        for (int i = f; i <= r; i++) printf("%d ", q[i]);
        printf("\n");
    }
}

int main() {
    int ch, val;
    while (1) {
        printf("1-Enq 2-Deq 3-Disp 4-Quit: ");
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &val); enqueue(val); }
        else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else if (ch == 4) break;
        else printf("Invalid\n");
    }
    return 0;
}

