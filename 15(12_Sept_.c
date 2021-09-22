#include<stdio.h>
#include<cstdlib>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *createNode(int x){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    if(head == NULL){
        head = ptr;
    }
    return ptr;
}
void display(){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d->", ptr->data);
        ptr=ptr->next;
    }
}
int main() {
    struct node *firstNode = createNode(5);
    struct node *secondNode = createNode(10);
    firstNode->next = secondNode;
    display();
    return 0;
}