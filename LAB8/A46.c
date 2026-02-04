#include<stdio.h>
#define size 10

void Enqueue(int queue[], int *rear, int *front, int value) {
    if (*rear == size - 1) {
        printf("Queue is full\n");
    } 
    else {
        if (*front == -1) {
            *front = 0; 
        }  
        *rear = *rear + 1;
        queue[*rear] = value;
        printf("%d \n", value);
    }

}
void Dequeue(int queue[], int *rear, int *front) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is empty\n"); 
    }
    else {
        printf("Deleted %d\n", queue[*front]);
        *front = *front + 1;
    }       
}

void Display(int queue[], int rear, int front) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");     
    }
    else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }           
}


void main(){
    int queue[size];
    int front = -1, rear = -1;
    Dequeue(queue, &rear, &front);
    Enqueue(queue, &rear, &front, 10);
    Enqueue(queue, &rear, &front, 20);
    Enqueue(queue, &rear, &front, 30);
    Display(queue, rear, front);
    
}