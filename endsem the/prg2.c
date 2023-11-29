#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int top=-1;
char stack[MAX];
void push(char c);
char pop();
int main()
{
    char exp[MAX],temp;
    int i,flag=1;
    printf("Enter an expression: ");
    gets(exp);
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            if(top==-1)
                flag=0;
            else
            {
                temp=pop();
                if(exp[i]==')' && (temp=='{' || temp=='['))
                    flag=0;
                if(exp[i]=='}' && (temp=='(' || temp=='['))
                    flag=0;
                if(exp[i]==']' && (temp=='(' || temp=='{'))
                    flag=0;
            }
    }
    if(top>=0)
        flag=0;
    if(flag==1)
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");
    return 0;
}

void push(char c)
{
    stack[++top]=c;
}

char pop()
{
    return(stack[top--]);
}
