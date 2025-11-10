#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int parent[MAX];
int rank[MAX];
void makeset(int x) {
    if (parent[x] != -1) {
        printf("\nElement %d is already in the set\n", x);
        return;
    }
    parent[x] = x;
    rank[x] = 0;
    printf("\nSet created for element %d\n", x);
}
int findset(int x) {
    if (parent[x] == x)
        return x;
    parent[x] = findset(parent[x]); 
    return parent[x];
}
void unionset(int x, int y) {
    int px = findset(x);
    int py = findset(y);

    if (px == py) {
        printf("\nElements %d and %d are already in the same set\n", x, y);
        return;
    }

    if (rank[px] < rank[py])
        parent[px] = py;
    else if (rank[px] > rank[py])
        parent[py] = px;
    else {
        parent[py] = px;
        rank[px]++;
    }

    printf("\nUnion done for %d and %d\n", x, y);
}
void display(int n) {
    printf("\nElement : Parent\n");
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1)
            printf("%d : %d\n", i, parent[i]);
    }
}

int main() {
    int n, ch, x, y;
    printf("Enter number of elements (<= %d): ", MAX);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    while (1) {
        printf("\n1. Make Set\n2. Find Set\n3. Union\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                makeset(x);
                break;

            case 2:
                printf("Enter element to find: ");
                scanf("%d", &x);
                if (parent[x] == -1)
                    printf("Element %d not found\n", x);
                else
                    printf("Representative of %d is %d\n", x, findset(x));
                break;

            case 3:
                printf("Enter two elements to union: ");
                scanf("%d%d", &x, &y);
                if (parent[x] == -1 || parent[y] == -1)
                    printf("One or both elements not found\n");
                else
                    unionset(x, y);
                break;

            case 4:
                display(n);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

