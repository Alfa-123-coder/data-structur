#include <stdio.h>

int stack[100], choice, n, top, x, i;

void push(void);
void pop(void);
void display(void);

int main()
{
    top = -1; 

    printf("\nEnter the size of stack: ");
    scanf("%d", &n);

    printf("\nStack operations using array");
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");

    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nExiting.....\n");
            break;

        default:
            printf("\nPlease enter a valid choice (1/2/3/4)");
            break;
        }
    } while (choice != 4);

    return 0;
}

void push()
{
    if (top >= n - 1)
    {
        printf("\nStack overflow");
    }
    else
    {
        printf("Enter a value to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("\n%d pushed onto stack", x);
    }
}

void pop()
{
    if (top <= -1)
    {
        printf("\nStack underflow");
    }
    else
    {
        printf("\nPopped element is %d", stack[top]);
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        printf("\nElements in stack are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
    else
    {
        printf("\nStack is empty");
    }
}

