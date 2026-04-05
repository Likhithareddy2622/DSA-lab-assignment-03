#include <stdio.h>
#include <stdlib.h>
#define MAX 5 
int stack[MAX], top = -1;
void push();
void pop();
void peek();
void display();
int main() {
    int choice;
    while (1) {
        printf("\n--- Stack Operations Menu ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}
void push() {
    int val;
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot add more elements.");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
        printf("Value %d pushed onto stack.", val);
    }
}
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No elements to pop.");
    } else {
        printf("\nPopped element: %d", stack[top]);
        top--;
    }
}
void peek() {
    if (top == -1) {
        printf("\nStack is empty.");
    } else {
        printf("\nTop element is: %d", stack[top]);
    }
}
void display() {
    if (top == -1) {
        printf("\nStack is empty.");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
