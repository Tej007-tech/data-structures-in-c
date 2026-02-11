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

// void FG(struct Node* head){
//     //  if(head->data == 0){
//     //      return head->data;
//     //  }

//      int i;
//      for(i=0;i<head->data || i<head->next->data;i++){
//             if(head->data % i == 0 && head->next->data % i == 0){
                
//             }
//      }
// }

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void GCD(struct Node* head) {
    while (head != NULL && head->next != NULL) {
        int FG = gcd(head->data, head->next->data);
        struct Node* newNode = createNode(FG);
        newNode->next = head->next;
        head->next = newNode;
        head = newNode->next;
    }
}

void main(){
            struct Node* head = NULL;

    insertEnd(&head,18);
    insertEnd(&head, 6);
    insertEnd(&head, 10);
    insertEnd(&head, 3);
    
    printList(head);


    GCD(head);
    

    printList(head);
}