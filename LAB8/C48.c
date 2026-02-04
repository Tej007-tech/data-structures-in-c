#include <stdio.h>
#define size 10

int f = -1, r = -1;

void DoubledInsert(int queue[], int value) {
    if ((f == 0 && r == size - 1) || (f == r + 1)) {
        printf("Queue is full\n");
        return;
    }
    if (f == -1) {
        f = 0;
        r = 0;
    } else {
        r = (r + 1) % size;
    }
    queue[r] = value;  
}

void DoubledDelete(int queue[]) {   
    if (f == -1) {
        printf("Queue is empty\n");
        return;
    }
    int y = queue[f];
    if (f == r) {
        f = -1;   
        r = -1;
    } else {
        f = (f + 1) % size;
    }
    printf("Deleted %d\n", y);
}

void DoubledDisplay(int queue[]) {
    if (f == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = f;
    while (1) {
        printf("%d ", queue[i]);
        if (i == r) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {   
    int queue[size];

    DoubledDelete(queue);        
    DoubledInsert(queue, 10);    
    DoubledInsert(queue, 20);    
    DoubledInsert(queue, 30);    
    DoubledDisplay(queue);

    DoubledDelete(queue);
    DoubledDisplay(queue);

    return 0;
}
