#include <stdio.h>
#define size 15
int s[15];
int top = -1;
// push

void push(int n)
{
    if (top >= 15)
    {
        printf("over Flow: ");
        return;
    }
    s[++top] = n;
}

// pop
int pop()
{
    if (top == -1)
    {
        printf("UnderFlow: ");
        return (0);
    }
    return s[top--];
}
// peep

void peep(int I)
{
    if (top - I + 1 <= 0)
    {
        printf("UnderFlow: ");
        return;
    }
    printf("%d ",s[top - I + 1 ]);
}

// CHANGE
void change(int I, int value)
{
    if (top - I + 1 <= 0)
    {
        printf("UnderFlow: ");
        return;
    }
    s[top - I + 1] = value;
    return;
}

// display
void display()
{
    int M = top;
    while (M >= 0)
    {
        printf("%d  ", s[M]);
        M--;
    }
}

void main()
{
    push(5);
    push(10);
    push(15);
    push(20);
    //pop();
    //display();
    //printf("\n");
    //change(2,25);
    peep(3);
    display();
}