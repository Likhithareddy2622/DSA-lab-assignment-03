#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;             
    struct node *next;    
};
struct node *top = NULL;
void push()
{
    struct node *newnode;
    int value;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Stack Overflow (Memory not available)\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("Element inserted successfully\n");
}
void pop()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack Underflow (Stack is empty)\n");
        return;
    }
    temp = top;
    top = top->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}
void peek()
{
    if(top == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}
void display()
{
    struct node *temp = top;

    if(temp == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements (Top to Bottom):\n");
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice;
    do
    {
        printf("\nSTACK USING LINKED LIST\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting program\n"); break;
            default: printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}