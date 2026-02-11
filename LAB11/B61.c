#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data;
    struct Node *next;
};

struct Queue *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Queue *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Queue *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else {
            break;
        }
    }
    return 0;
}