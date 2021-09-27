#include<stdio.h>
#include<cstdlib>
struct node {
    int data;
    struct node *next;
    struct node *random;
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
struct node *function(struct node *head) {
    struct node *newHead = NULL;
    struct node *k = head;
    struct node *j = head->next;
    while(k!=NULL) {
        struct node *temp = createNode(k->data);
        if(newHead == NULL) {
            newHead = temp;
        }
        k->next = temp;
        temp->next = j;
    }
    struct node *j = newHead;
    struct node *b = head;
    while(b!=NULL) {
        j->random = b->random->next;
        j = j->next->next;
        b = b->next->next;
    }
    return newHead;
}
int main() {
    return 0;
}