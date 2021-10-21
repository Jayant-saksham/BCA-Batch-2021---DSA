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
int height(struct node *ptr) {
    if(ptr == NULL) {
        return 0;
    }
    int leftHeight = height(ptr->left);
    int rightHeight = height(ptr->right);
    if(leftHeight>rightHeight) {
        return 1 + leftHeight;
    }
    return 1 + rightHeight;
}
struct node *takeInput() {
    int x;
    printf("Enter data : ");
    scanf("%d", &x);
    if(x == -1) {
        return NULL;
    }
    struct node *ptr = createNode(x);
    struct node *leftChild = takeInput();
    struct node *rightChild = takeInput();
    ptr->left = leftChild;
    ptr->right = rightChild;
    return ptr;
}
int count(struct node *ptr) {
    if(ptr == NULL) {
        return 0;
    }
    int leftCount = count(ptr->left);
    int rightCount = count(ptr->right);
    return leftCount + rightCount + 1;
}
int main() {
    root = takeInput();
    printf("Height is %d",height(root));
    return 0;
}