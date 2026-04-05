#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 10   
char stack[max];
int top = -1;
void push(char ch)
{
    if (top == max - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        top++;              
        stack[top] = ch;    
    }
}
char pop()
{
    char ch;
    ch = stack[top];   
    top--;             
    return ch;         
}
int precedence(char ch)
{
    if (ch == '^')
        return 3;

    else if (ch == '*' || ch == '/')
        return 2;

    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
int main()
{
    char infix[100];   
    char postfix[100];   
    int j = 0;           
    printf("Please enter the infix expression: ");
    scanf("%s", infix);
    for(int i = 0; i < strlen(infix); i++)
    {
        if(isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '(')
        {
            push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
        }
    }
    while(top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}