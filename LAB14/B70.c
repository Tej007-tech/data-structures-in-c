//  WAP to split a circular linked list into two halves. 



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } 
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = *head;
    
}


void printList(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    int first = 1;
    while (temp != head || first) {
        first = 0;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void splitList(struct Node* head, struct Node** head1, struct Node** head2) {
    if (head == NULL || head->next == head)
        return;

    struct Node *slow = head, *fast = head;

    
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    
    *head1 = head;
    *head2 = slow->next;

   
    slow->next = *head1;

    
    if (fast->next == head){ 
        fast->next = *head2;
    }
    else {
        fast->next->next = *head2;
    }
}


int main() {
    struct Node* head = NULL;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    printf(" Circular ");
    printList(head);
    printf("\n");

    splitList(head, &head1, &head2);

    printf("First Half: ");
    printList(head1);
    printf("\n");
    printf("Second Half: ");
    printList(head2);

    return 0;
}
