/*56. Write a program to implement a node structure for singly linked list.
 Read the data in a node, print the node.*/
 #include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void main()
{
    struct node list[3];

    list[0].info = 10;
    list[1].info = 20;
    list[2].info = 30;

    list[0].link = &list[1];
    list[1].link = &list[2];
    list[2].link = NULL;

    for (int i = 0; i < 3; i++)
    {
        printf("info:%d \t  link: %d \n ", list[i].info, list[i].link);
    }

    printf("Enter 4th node info:");
    scanf("%d", &list[3].info);
    list[2].link = &list[3];
    list[3].link = NULL;

    for (int i = 0; i <= 3; i++)
    {
        printf("info:%d \t  link: %d \n ", list[i].info, list[i].link);
    }
}