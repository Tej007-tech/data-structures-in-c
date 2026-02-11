#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int Count(struct Node* root){
    if(root == NULL) return 0;
    int count=0;

    int LCount = Count(root->left);
    int RCount = Count(root->right);

    int Diff = (LCount > RCount) ? LCount - RCount : RCount - LCount;

    if(Diff > 1){
        return 0;
    }
    else{
        return 1;
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(3);
    root->left->left->left = createNode(4);
     root->left->left->right = createNode(4);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    int a = Count(root);

    if(a == 1){
        printf("true ");
    }
    else{
        printf("False");
    }
    return 0;
}
