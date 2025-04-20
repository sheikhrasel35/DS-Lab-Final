
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
} Student;

typedef struct {
    Student data[MAX_SIZE];
    int front, rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    return (q->rear == MAX_SIZE - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, char *name) {
    if (isFull(q)) {
        printf("Queue is full. Cannot add more students.\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    strcpy(q->data[q->rear].name, name);
    printf("%s added to queue.\n", name);
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No students to serve.\n");
        return;
    }

    printf("Serving student: %s\n", q->data[q->front].name);
    q->front++;

    if (q->front > q->rear) {
        initializeQueue(q);
    }
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current queue:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d. %s\n", i - q->front + 1, q->data[i].name);
    }
}

int main() {
    Queue ticketQueue;
    initializeQueue(&ticketQueue);
    int choice;
    char name[50];

    while (1) {
        printf("\nDIU Ticketing System\n");
        printf("1. New Arrival (Enqueue)\n");
        printf("2. Serve Student (Dequeue)\n");
        printf("3. Show Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student name: ");
                scanf("%s", name);
                enqueue(&ticketQueue, name);
                break;
            case 2:
                dequeue(&ticketQueue);
                break;
            case 3:
                displayQueue(&ticketQueue);
                break;
            case 4:
                printf("Exiting system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
