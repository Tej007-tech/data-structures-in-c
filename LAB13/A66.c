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

void sortList(struct Node* head) {
    if (head == NULL || head->next == NULL) return;

    struct Node *h1, *h2;
    int temp;

    for (h1 = head; h1 != NULL; h1 = h1->next) {
        for (h2 = h1->next; h2 != NULL; h2 = h2->next) {
            if (h2->data > h2->data) {
                
                temp = h1->data;
                h1->data = h2->data;
                h2->data = temp;
            }
        }
    }
    while (head != NULL)
        {
            printList(head);
        }
}
void AfterSort(struct Node* head){
        
        
}

void main(){
            struct Node* head = NULL;

    insertEnd(&head,30);
    insertEnd(&head, 60);
    insertEnd(&head, 50);
    insertEnd(&head, 10);
    insertEnd(&head, 49);

    
    printList(head);
    sortList(head);
}