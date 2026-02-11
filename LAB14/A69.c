//  Write a menu driven program to implement following operations on the circular 
// linked list. 
// • Insert a node at the front of the linked list. 
// • Delete a node from specified position. 
// • Insert a node at the end of the linked list. 
// • Display all nodes.



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* last = NULL;



void insertFront(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        
        newNode->next = newNode;
        head = newNode;
        last = newNode;
    }
     else {
        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }
}

void insertLast(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        last = newNode;
    } else {
        newNode->next = head;
        last->next = newNode;
        last = newNode;
    }
}


void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    
    if (pos == 1) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } 
        else {
            struct Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = head->next;
            temp = head;
            head = head->next;
            free(temp);
        }
        return;
    }

    
    struct Node* prev = NULL;
    int i = 1;
    while (i < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (i != pos) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}


int main() {
    int choice, val, pos;

    insertFront(10);
    insertFront(20);
    insertFront(30);
    insertFront(40);
    insertFront(50);

    

    display();
    insertLast(50);
    display();

    while (1) {
        printf("\nCircular Linked List Operations\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert at front: ");
                
                insertFront(2);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                
                insertEnd(10);
                break;

            case 3:
                printf("Enter position to delete: ");
                
                deleteAtPosition(3);
                break;

            case 4:
                display();
                break;
            
            
            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid\n");
        }
    }

    return 0;
}
