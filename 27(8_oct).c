#include<stdio.h>
#include<cstdlib>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
void preorder(struct node *ptr) {
    if(ptr == NULL) {
        return;
    }
    printf("%d ", ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}
void postorder(struct node *ptr) {
    if(ptr == NULL) {
        return;
    }
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d ", ptr->data);
}
void inorder(struct node *ptr) {
    if(ptr == NULL) {
        return;
    }
    inorder(ptr->left);
    printf("%d ", ptr->data);
    inorder(ptr->right);
}
struct node *createNode(int x) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
int main() {
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    inorder(root);
    return 0;
}