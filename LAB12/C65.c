//  WAP to swap Kth node from beginning with Kth node from end in a singly linked 
// list.


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


int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


void swapKth(struct Node** head, int k) {
    int n = countNodes(*head);
    
    if (k > n) {
        printf("K is greater than number of nodes.\n");
        return;
    }
    if (2 * k - 1 == n) {
        return;
    }

    
    struct Node* x = *head;
    struct Node* xprev = NULL;
    for (int i = 1; i < k; i++) {
        xprev = x;
        x = x->next;
    }

    
    struct Node* y = *head;
    struct Node* yprev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        yprev = y;
        y = y->next;
    }

    
    if (xprev)
        xprev->next = y;
    else
        *head = y;

    
    if (yprev)
        yprev->next = x;
    else
        *head = x;

    
    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
}


int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Original List:\n");
    printList(head);

    int k = 2;
    swapKth(&head, k);

    printf("\n %d :\n", k);
    printList(head);

    return 0;
}
