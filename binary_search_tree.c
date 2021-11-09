#include<stdio.h>
#include<cstdlib>
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void inOrder(struct node *root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(struct node *root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

struct node * insert(struct node *root, int x) {
    if(root == NULL) {
        struct node *ptr;
        ptr = createNode(x);
        return ptr;
    }
    if(root->data < x) {
        root->right = insert(root->right, x);
    }
    else if(root->data > x) {
        root->left = insert(root->left, x);
    }
    return root;
}

struct node *minValueNode(struct node *root) {
    if(root == NULL) {
        return NULL;
    }
    struct node *current = root;
    while(current->left!=NULL) {
        current = current->left;
    }
    return current;
}

struct node *maxValueNode(struct node *root) {
    if(root == NULL) {
        return NULL;
    }
    struct node *current = root;
    while(current->right!=NULL) {
        current = current->right;
    }
    return current;
}

struct node *deleteNode(struct node *root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data < key) {
        root->right = deleteNode(root->right, key);
    }
    else if(root->data > key) {
        root->left = deleteNode(root->left, key);
    }
    else {
        // zero child (18 se kam)
        if(root->left == NULL && root->right == NULL) {
            return NULL;
        }
        // One child
        else if(root->left == NULL && root->right != NULL) {
            struct node *ptr = root->right;
            free(root);
            return ptr;
        }
        else if(root->left != NULL && root->right == NULL) {
            struct node *ptr = root->left;
            free(root);
            return ptr;
        }
        // Two child
        struct node *ptr = maxValueNode(root->left);
        root->data = ptr->data;
        root->left = deleteNode(root->left, ptr->data);
    }
    return root;
}

int main() {
    struct node *root = NULL;
    int A[] = {5,12,17,13,14,15,4};
    int n = sizeof(A)/sizeof(A[0]);
    for(int i=0;i<n;i++) {
        root = insert(root, A[i]);
    }
    deleteNode(root, 5);
    inOrder(root);
    return 0;
}