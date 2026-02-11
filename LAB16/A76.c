
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}

int Sametree(struct Node *p, struct Node *q)
{
    if (p == NULL && q == NULL)
    {
        return 1;
    }
    else if (p == NULL || q == NULL || p->data != q->data)
    {
        return 0;
    }

    return Sametree(p->left, q->left) && Sametree(p->right, q->right);
}

int main()
{
    struct Node *root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    struct Node *root2 = NULL;
    root2 = insertNode(root2, 50);
    root2 = insertNode(root2, 30);
    root2 = insertNode(root2, 70);
    root2 = insertNode(root2, 20);
    root2 = insertNode(root2, 100);
    root2 = insertNode(root2, 60);
    root2 = insertNode(root2, 80);

    int a = Sametree(root, root2);

    if (a == 1)
    {
        printf("same tree: ");
    }
    else
    {
        printf("Not same tree: ");
    }
    return 0;
}