// 73. WAP to delete alternate nodes of a doubly linked list. 


#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;


void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


void printList() {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d<=>", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void deleteAlternate() {
    struct Node* temp = head;
    struct Node* Dl;

    while (temp != NULL && temp->next != NULL) {
        Dl = temp->next;

        
        temp->next = Dl->next;

        if (Dl->next != NULL)
            Dl->next->prev = temp;

        free(Dl);

       
        temp = temp->next;
    }
}


int main() {
    
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    printf(" List:\n");
    printList();

    deleteAlternate();

    printf("After Deleting :\n");
    printList();

    return 0;
}
