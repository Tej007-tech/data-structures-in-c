// 57. Write a menu driven program to implement following operations on the singly 
// linked list.  
// • Insert a node at the front of the linked list. 
// • Display all nodes. 
// • Delete a first node of the linked list. 
// • Insert a node at the end of the linked list. 
// • Delete a last node of the linked list. 
// • Delete a node from specified position. 
// • count the number of nodes


#include<stdio.h>
#include<stdlib.h>
struct node 
{
    /* data */
    int info;
    struct node *link;
   
    
};

struct  node *first = NULL;

int main(){
         int choice,*save;
         printf("Insert a node at the front of the linked list.\n"); 
         printf("Display all nodes.\n"); 
         printf("Delete a first node of the linked list.\n");
         printf("Insert a node at the end of the linked list.\n");
         printf("Delete a last node of the linked list.\n");
         printf("Delete a node from specified position.\n"); 
         printf("count the number of nodes.\n");

         printf("Enter your Choice");
         scanf("%d",&choice);
        

    switch (choice)
    {
    case 1:
        /* code */
        int X;
        printf("Enter number: ");
        scanf("%d",&X);
        insertAtFirst(X);
        break;
    case 2:
        int X;
        printf("Enter number: ");
        scanf("%d",&X);
         Display(X);
         break;

    case 3:
        int X;
        printf("Enter number: ");
        scanf("%d",&X);
        deletefirstnode(X);
        break;
    default:
        break;
    }
      return 0;
}

// • Insert a node at the front of the linked list. 
void insertAtFirst(int X){
     struct  node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));

     newnode->info = X;
     newnode->link = first;

     first = newnode;
     
}

// • Insert a node at the end of the linked list.
void insertAtend(int X){
    if(first->link == NULL){
         printf("Linked list Empty");
    } 
    struct  node *newnode;
     newnode = (struct node *)malloc(sizeof(struct node));

     newnode->info = X;
     newnode->link = NULL;
     struct node *save;
     save = first;

     while(save->link != NULL){
        save = save->link;
     }
     save->link = newnode;
}

// • count the number of nodes

void countNode(int X){
      struct node *count;
      count = 0;
      struct  node *newnode;
      newnode = (struct node *)malloc(sizeof(struct node));
      newnode->info = X;
     newnode->link = NULL;
     struct node *save;
     save = first;

      while(save->link != NULL){
        count++;
        save = save->link;
    }
    printf("%d",count);
}

// • Display all nodes. 

void Display(int X)
{
    
      struct  node *newnode;
      newnode = (struct node *)malloc(sizeof(struct node));
      newnode->info = X;
     newnode->link = NULL;
     struct node *save;
     save = first;

      while(save->link != NULL)
      {
        
        save = save->link;
        printf("%d ",save->info);
    }
    
}

// • Delete a first node of the linked list. 
void deletefirstnode(int X)
{
      if(first == NULL)
      {
         printf("Linked list Empty");
      }
      struct node *save = first;

      if(save->info == X)
      {
        first = save->link;
        free(save);
      }
      
}


// • Delete a last node of the linked list. 
 
void deleteEndnode(int X){
      
      struct node *save = first;
      while(save->link != NULL)
      {
         first = save->link;
         free(save);   

      }
      
      
}
