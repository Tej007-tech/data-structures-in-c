//  WAP to check whether 2 singly linked lists are same or not.

#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node* link;
};


struct node* createNode(int data)
 {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->link = NULL;
    return newNode;
}


int areSame(struct node* h1, struct node* h2) 
{
    while (h1 != NULL && h2 != NULL)
     {
        if (h1->info != h2->info) 
        {
            return 0;  
        }
        h1 = h1->link;
        h2 = h2->link;
    }
    
    if (h1 != NULL || h2 != NULL)
     {
        return 0;
    }
    return 1; 
}


void compare(struct node** head, int data)
 {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
       temp->link = newNode;
}
   

int main() 
{
    struct node* l1 = NULL;
    struct node* l2 = NULL;

    
    compare(&l1, 10);
    compare(&l1, 20);
    compare(&l1, 30);

    
    compare(&l2, 10);
    compare(&l2, 20);
    compare(&l2, 30);


    

    
    if (areSame(l1, l2)) 
    {
        printf(" SAME.\n");
    } else {
        printf("DIFFERENT.\n");
    }

    return 0;
}
