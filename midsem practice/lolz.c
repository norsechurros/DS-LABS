#include <stdio.h>

// Function prototypes


typedef struct
{
    int top;
    int arr[100];
} st;
void init(st *stack);
int push(int ele, st *stack);
int pop(st *stack);
int main()
{
    st stack;
    init(&stack); // Initialize the stack

    int ch, ele;
    do
    {
        printf("Enter 1 to push, 2 to pop, and 3 to terminate: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to be pushed on the stack: ");
            scanf("%d", &ele);
            push(ele, &stack);
            break;

        case 2:
            pop(&stack);
            break;

        case 3:
            // Terminate the program
            return 0;

        default:
            printf("Invalid input!\n");
        }
    } while (1); // Infinite loop until terminated

    return 0;
}

// Initialize the stack
void init(st *stack)
{
    stack->top = -1;
}

// Push an element onto the stack
int push(int ele, st *stack)
{
    if (stack->top >= 99)
    {
        printf("Stack overflow\n");
        return -1; // Indicate failure
    }
    else
    {
        stack->arr[++stack->top] = ele;
        return 0; // Indicate success
    }
}

// Pop an element from the stack
int pop(st *stack)
{
    if (stack->top <= -1)
    {
        printf("Stack underflow\n");
        return -1; // Indicate failure
    }
    else
    {
        int popped = stack->arr[stack->top--];
        printf("Popped element is: %d\n", popped);
        return popped; // Return the popped element
    }
}
