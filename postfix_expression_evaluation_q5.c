#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value)
{
    top++;
    stack[top] = value;
}
int pop()
{
    int value;
    value = stack[top];
    top--;
    return value;
}
int main()
{
    char postfix[100];
    int i, A, B, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    for(i = 0; i < strlen(postfix); i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');   
        }
        else
        {
            A = pop();   
            B = pop();   
            if(postfix[i] == '+')
                result = B + A;
            else if(postfix[i] == '-')
                result = B - A;
            else if(postfix[i] == '*')
                result = B * A;
            else if(postfix[i] == '/')
                result = B / A;
            push(result);
        }
    }
    printf("Result = %d\n", pop());
    return 0;
}