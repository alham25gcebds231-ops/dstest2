#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Element {
    int data;
    int priority;
};

struct Element pq[MAX];
int count = 0;

void enqueue(int val, int prio) {
    if (count == MAX) {
        printf("Priority queue is full.\n");
        return;
    }
    int i = count - 1;
    while (i >= 0 && pq[i].priority > prio) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1].data = val;
    pq[i + 1].priority = prio;
    count++;
}

int dequeue() {
    if (count == 0) {
        printf("Priority queue is empty.\n");
        exit(1);
    }
    int val = pq[0].data;
    for (int i = 0; i < count - 1; i++) {
        pq[i] = pq[i + 1];
    }
    count--;
    return val;
}

int isEmpty() {
    return count == 0;
}

void display() {
    if (count == 0) {
        printf("Priority queue is empty.\n");
        return;
    }
    printf("Priority queue elements:\n");
    for (int i = 0; i < count; i++) {
        printf("Data: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
    printf("\n");
}

int main() {
    int opt, item, prio;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter data and priority to enqueue: ");
                scanf("%d %d", &item, &prio);
                enqueue(item, prio);
                display();
                break;
            case 2:
                if (!isEmpty()) {
                    printf("Dequeued element: %d\n", dequeue());
                    display();
                } else {
                    printf("Priority queue is empty.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}