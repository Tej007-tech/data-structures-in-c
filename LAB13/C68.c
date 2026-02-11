#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* swap(struct Node* head) {
    
    struct Node D;
    D.next = head;
    struct Node* prev = &D;

    while (head && head->next != NULL) {
        struct Node* first = head;
        struct Node* second = head->next;

       
        prev->next = second;
        first->next = second->next;
        second->next = first;

       
        prev = first;
        head = first->next;
    }

    return D.next;
}

void main(){
            struct Node* head = NULL;

    insertEnd(&head,1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);
    insertEnd(&head, 7);
    insertEnd(&head, 8);
    
    printList(head);


    
    swap(head);

    printList(head);
}