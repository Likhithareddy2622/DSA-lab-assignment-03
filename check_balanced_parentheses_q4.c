#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
struct Stack {
    int top;
    char items[MAX];
};
void push(struct Stack* s, char c) {
    if (s->top == MAX - 1) {
        return;
    }
    s->items[++(s->top)] = c;
}
char pop(struct Stack* s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->items[(s->top)--];
}
bool isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return true;
    if (char1 == '{' && char2 == '}') return true;
    if (char1 == '[' && char2 == ']') return true;
    return false;
}
bool isBalanced(char* exp) {
    struct Stack s;
    s.top = -1;
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            push(&s, exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (s.top == -1) {
                return false; 
            } else if (!isMatchingPair(pop(&s), exp[i])) {
                return false; 
            }
        }
    }
    return (s.top == -1);
}

int main() {
    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (isBalanced(exp)) {
        printf("Valid Expression\n");
    } else {
        printf("Invalid Expression\n");
    }

    return 0;
}
