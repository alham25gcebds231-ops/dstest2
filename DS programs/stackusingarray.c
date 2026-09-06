#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

int push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return -1;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
    return value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int poppedValue = stack[top--];
    printf("%d popped from stack.\n", poppedValue);
    return poppedValue;
}

int peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    printf("Top element: %d\n", stack[top]);
    return stack[top];
}

int display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
    return 0;
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}