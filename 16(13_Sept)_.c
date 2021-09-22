#include<stdio.h>
#include<cstdlib>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node* createNode(int x){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(head==NULL) {
        head = ptr;
        tail = ptr;
    }
    ptr->data=x;
    ptr->next=NULL;
    return ptr;
}
void displayLL(){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d->", ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}
void createLL(int A[], int n){
    struct node *firstNode = createNode(A[0]);
    for(int i=1;i<n;i++){
        struct node *ptr=createNode(A[i]);
        tail->next=ptr;
        tail = ptr;
    }
}
void deleteLast() {
    if(head==NULL){
        printf("No linked list is there");
        return;
    }
    struct node *ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    tail = ptr;
    ptr=ptr->next;
    free(ptr);
    tail->next=NULL;
}
int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    createLL(A, n);
    displayLL();
    deleteLast();
    deleteLast();
    printf("\n");
    displayLL();
    return 0;
}