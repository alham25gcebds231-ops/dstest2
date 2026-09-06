#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return -1;
    }
    return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void infixToPostfix(char* infix) {
    char postfix[MAX];
    int i = 0, k = 0;
    char symbol;

    while (infix[i] != '\0') {
        symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[k++] = symbol;
        } 
        else if (symbol == '(') {
            push(symbol);
        } 
        else if (symbol == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        } 
        else {
            while (top != -1 && precedence(peek()) >= precedence(symbol)) {
                if (symbol == '^' && peek() == '^') {
                    break;
                }
                postfix[k++] = pop();
            }
            push(symbol);
        }
        i++;
    }

    while (top != -1) {
        postfix[k++] = pop();
    }
    
    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}