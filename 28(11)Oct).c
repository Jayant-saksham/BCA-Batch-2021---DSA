#include<stdio.h>
#include<cstdlib>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *createNode(int x) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
void preOrder(struct node *ptr) {
    if(ptr == NULL) {
        return;
    }
    printf("%d ", ptr->data);
    preOrder(ptr->left);
    preOrder(ptr->right);
}
void printTree(struct node *root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    if(root->left!=NULL) {
        printf("L : %d", root->left->data);
    }
    if(root->right!=NULL) {
        printf("R : %d", root->right->data);
    }
    printf("\n");
    printTree(root->left);
    printTree(root->right);
}
struct node * treeInput() {
    int x;
    printf("Enter data : ");
    scanf("%d", &x);
    if(x == -1) {
        return NULL;
    }
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    struct node *leftTreeRoot = treeInput();
    struct node *rightTreeRoot = treeInput();
    ptr->left = leftTreeRoot;
    ptr->right = rightTreeRoot;
    return ptr;    
}
int main() {
    root = treeInput();
    printTree(root);
    return 0;
}