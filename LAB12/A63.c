#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node *link;
};


struct node* copy(struct node *first) {
    if (first == NULL) return NULL;

    
    struct node *copyHead = (struct node *)malloc(sizeof(struct node));
    copyHead->info = first->info;
    copyHead->link = NULL;

    struct node *currOriginal = first->link;
    struct node *currCopy = copyHead;

    while (currOriginal != NULL) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = currOriginal->info;
        newNode->link = NULL;

        currCopy->link = newNode;
        currCopy = newNode;
        currOriginal = currOriginal->link;
    }

    return copyHead;
}


void printList(struct node *head) {
    while (head!= NULL) {
        printf("%d ", head->info);
        head = head->link;
    }
    printf("\n");
}

void main() {
    
    struct node list[6];
    list[0].info = 5;
    list[1].info = 6;
    list[2].info = 7;
    list[3].info = 8;
    list[4].info = 9;
    

    
    list[0].link = &list[1];
    list[1].link = &list[2];
    list[2].link = &list[3];
    list[3].link = &list[4];
    
    list[4].link = NULL;

    struct node *first = &list[0];

    printf("Original list: ");
    printList(first);

    struct node *copiedList = copy(first);

    printf("Copied list: ");
    printList(copiedList );
}