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

int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(30);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(40);
    root->right->right = createNode(20);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    if (isSymmetric(root))
        printf("Symmetric tree");
    else
        printf("Not symmetric tree");

    return 0;
}
