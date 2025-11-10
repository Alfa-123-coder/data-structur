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

