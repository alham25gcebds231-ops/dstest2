#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void enqueue(int num) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (!ptr) {
        printf("Memory allocation failed!\n");
        return;
    }
    ptr->val = num;
    ptr->next = NULL;
    if (tail == NULL) {
        head = tail = ptr;
    } else {
        tail->next = ptr;
        tail = ptr;
    }
    printf("%d enqueued to the queue.\n", num);
}

void dequeue() {
    if (head == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("%d dequeued from the queue.\n", temp->val);
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
}

void peek() {
    if (head == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Front element is: %d\n", head->val);
    }
}

void display() {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* curr = head;
    printf("Queue elements: ");
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int userChoice, data;

    while (1) {
        printf("\n--- Queue Menu (Linked List) ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}