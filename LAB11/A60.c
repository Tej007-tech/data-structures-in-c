#include <stdio.h>
#include <stdlib.h>
struct stack {
    int data;
    struct stack *next;
};
struct stack *top = NULL;
void push(int val) {
    struct stack *newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct stack *temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
}
void display() {
    struct stack *temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, val;
    while (1) {
        printf("1.Push  2.Pop  3.Display  4.Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        } else {
            break;
        }
    }
    return 0;
}