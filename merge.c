#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[100], b[100];
    int n1, n2, i, j, temp, total, size = 0;

    printf("Enter how many elements in first array: ");
    scanf("%d", &n1);
    printf("Enter first array elements:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter how many elements in second array: ");
    scanf("%d", &n2);
    printf("Enter second array elements:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    // Merge arrays
    total = n1 + n2;
    for (i = n1; i < total; i++) {
        a[i] = b[size];
        size++;
    }

    // Bubble sort merged array
    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    printf("Sorted merged array elements are:\n");
    for (i = 0; i < total; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

