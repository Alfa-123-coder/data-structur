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
    printf("Set created for element %d\n", x);
}

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]); // Path compression
}

void union_sets(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py) {
        printf("\nElements %d and %d are already in the same set\n", x, y);
        return;
    }

    // Union by rank
    if (rank[px] < rank[py])
        parent[px] = py;
    else if (rank[px] > rank[py])
        parent[py] = px;
    else {
        parent[py] = px;
        rank[px]++;
    }

    printf("\nUnion done for elements %d and %d\n", x, y);
}

void display_sets(int n) {
    printf("\nElement : Parent\n");
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1)
            printf("%d : %d\n", i, parent[i]);
    }
}

int main() {
    int n, choice, x, y;
    printf("Enter number of elements (<= %d): ", MAX);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    while (1) {
        printf("\n1. Make Set\n2. Find\n3. Union\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                    printf("Representative of %d is %d\n", x, find(x));
                break;

            case 3:
                printf("Enter two elements to union: ");
                scanf("%d%d", &x, &y);
                if (parent[x] == -1 || parent[y] == -1)
                    printf("One or both elements not found\n");
                else
                    union_sets(x, y);
                break;

            case 4:
                display_sets(n);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

