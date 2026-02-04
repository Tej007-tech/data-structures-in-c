#include <stdio.h>
#define size 10

void Cqinsert(int queue[], int *rear, int *front, int value) {

    if ((*front == 0 && *rear == size - 1) || (*front == *rear + 1)) {
        printf("Queue is full\n");
        return;
    }
    if (*front == -1) {
        *front = 0;
        *rear = 0;
    } else {
        *rear = (*rear + 1) % size;
    }
    queue[*rear] = value;
   
}

int CqDelete(int queue[], int *rear, int *front) {
    if (*front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int y = queue[*front];
    if (*front == *rear) {
        *front = *rear = -1; 
    } else {
        *front = (*front + 1) % size;
    }
    return y;
}

void CqDisplay(int queue[], int rear, int front) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int queue[size];
    int front = -1, rear = -1;

    Cqinsert(queue, &rear, &front, 10);
    Cqinsert(queue, &rear, &front, 20);
    Cqinsert(queue, &rear, &front, 30);
    Cqinsert(queue, &rear, &front, 40);
    Cqinsert(queue, &rear, &front, 50);
    Cqinsert(queue, &rear, &front, 60);

    CqDisplay(queue, rear, front);

    printf("Deleted: %d\n", CqDelete(queue, &rear, &front));

    CqDisplay(queue, rear, front);

    return 0;
}
