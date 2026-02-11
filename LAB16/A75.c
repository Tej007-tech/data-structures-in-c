// 75. Write a menu driven program to implement Binary Search Tree (BST) & perform 
// following operations:  
// • Insert a node 
// • Delete a node 
// • Search a node 
// • Preorder Traversal 
// • Postorder Traversal 
// • Inorder Traversal





#include<stdio.h> 
#include<stdlib.h>

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

struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}

void Inorder(struct Node* root) {
    if (root) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

void Preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct Node* root) {
    if (root) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->data);
    }
}

int Search(struct Node* root, int value) {
    if (root == NULL) return 0;
    if (value == root->data) return 1;
    else if (value < root->data) return Search(root->left, value);
    else return Search(root->right, value);
}

struct Node* findmin(struct Node* root){
    struct Node* temp = root->right;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main(){
    struct  Node * root= NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    deleteNode(root,30);
    Inorder(root);
    printf("\n %d",Search(root,100));
    
     return 0; 
}