#include<stdio.h>
#include<cstdlib>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node *createNode(int x) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    return ptr;
}
void display() {
    struct node *ptr = head;
    while(ptr!=NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int size() {
    struct node *ptr = head;
    int count = 0;
    while(ptr!=NULL) {
        count++;
        ptr=ptr->next;
    }
    return count;
}
int front() {
    if(head == NULL) {
        return -1;
    }
    return head->data;
}
int rear() {
    if(head == NULL) {
        return -1;
    }
    return tail->data;
}
void delete() {
    if(head == NULL) {
        return ;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
}
int main() {

    return 0;
}