
#include <stdio.h>

int push(); int pop();

typedef struct
{
    int top;
    int arr[100];
}st;

void init()
{
    st stack;
    stack.top = -1;
    return stack;
}

int main()
{

    int ch,ele;

    printf("enter 1. to push or 2. to pop\n");
    scanf("%d",&ch);

    switch(ch)
    {

    case 1:
        printf("Enter value to be pushed on the stack: ");
        scanf("%d",&ele);
        push(ele);
        break;

    case 2: pop();

    default: printf("invalid input!");
    }
}

int push(int ele,st stack)
{
    if(stack.top>=100)
    {
        printf("Stack overflow\n");

    }
    else
        stack.arr[stack.top++] = ele;
        return 0;
}

int pop(st stack)
{
    if(stack.top<=-1)
    {
        printf("Stack underflow \n");

    }
    else{
        int popped = stack.arr[stack.top--];
        printf("popped element is: "+popped);
        return 0;}
}


