// 59. Write a program to remove the duplicates nodes from given sorted Linked List. 
// • Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
// • Output: 1 → 6 → 13 → 27 


#include <stdio.h>
#include <stdlib.h>


struct Node {
    int info;
    struct Node* list;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->list = NULL;
    return newNode;
}


void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->list != NULL)
        temp = temp->list;

    temp->list = newNode;
}


void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->list != NULL) {
        if (current->info == current->list->info) {
            struct Node* temp = current->list;
            current->list = current->list->list;
            free(temp);
        } else {
            current = current->list;
        }
    }
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->info);
        if (head->list != NULL)
            printf(" --> ");
        head = head->list;
    }
    printf("\n");
}


int main() {
    struct Node* head = NULL;

    
    int values[] = {1, 1, 6, 13, 13, 13, 27, 27};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        insertEnd(&head, values[i]);

    
    removeDuplicates(head);

    printf("New List :\n");
    printList(head);

    return 0;
}
