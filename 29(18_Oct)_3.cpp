#include<bits/stdc++.h>
using namespace std;
struct node{
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
struct node *levelOrderInput() {
  int x;
  printf("Enter the root data : ");
  scanf("%d", &x);
  if(x==-1) {
    return  NULL;
  }
  struct node *ptr = createNode(x);
  queue<struct node *> q;
  q.push(ptr);
  while(q.size() > 0) {
    struct node *front = q.front();
    q.pop();
    printf("Enter left of %d : ", front->data);
    int leftChild;
    scanf("%d", &leftChild);
    if(leftChild!=-1) {
      struct node *temp = createNode(leftChild);
      front->left = temp;
      q.push(temp);
    }
    printf("Enter the right child of %d : ", front->data);
    int rightChild;
    scanf("%d", &rightChild);
    if(rightChild!=-1) {
      struct node *temp = createNode(rightChild);
      front->right = temp;
      q.push(temp);
    }
  }
  return ptr;
}
void printLevelOrder(struct node *root) {
  if(root == NULL) {
    return;
  }
  queue<struct node *> q;
  q.push(root);
  while(q.size() > 0) {
    struct node *front = q.front();
    printf("%d ", front->data);
    q.pop();
    if(root->left!=NULL) {
      q.push(root->left);
    }
    if(root->right!=NULL) {
      q.push(root->right);
    }
  }
}
int main(){
    root = levelOrderInput();
    preOrder(root);
    return 0;
}