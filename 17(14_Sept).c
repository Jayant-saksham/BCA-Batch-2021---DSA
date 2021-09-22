#include<stdio.h>
#include<cstdlib>
struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node * createNode(int x) {
    struct node *ptr; 
    ptr = (struct node *)malloc(sizeof(struct node));
    if(head == NULL) {
        head=ptr;
        tail=ptr;
    }
    ptr->data = x;
    ptr->next = NULL;
    return ptr;
}
void display() {
    struct node *ptr=head;
    while(ptr!=NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
void createLL(int A[], int n) {
    struct node *ptr = createNode(A[0]);
    for(int i=1;i<n;i++) {
        struct node *temp = createNode(A[i]);
        tail->next = temp;
        tail = temp;
    }
}
void deleteFromLast() {
    struct node *ptr = head;
    while(ptr->next->next!=NULL) {
        ptr = ptr->next;
    }
    tail = ptr;
    ptr = ptr->next;
    free(ptr);
    tail->next = NULL;
}
void deleteFromFirst() {
    struct node *ptr=head;
    head=head->next;
    ptr->next=NULL;
    free(ptr);
}
int length() {
    int count = 0;
    struct node * ptr=head;
    while(ptr!=NULL) {
        count++;
        ptr=ptr->next;
    }
    return count;
}
void deleteFromIndex(int idx) {
    if(idx>=length() || idx<0) {
        printf("Invalid index!");
        return;
    }
    if(idx == 0) {
        deleteFromFirst();
    }
    else if(idx == length()-1) {
        deleteFromLast();
    }
    else {
        struct node *d = head;
        struct node *j = NULL;
        for(int i=0;i<idx;i++) {
            j = d;
            d = d->next;
        }
        j->next = d->next;
        d->next = NULL;
        free(d);
    }
}
void reverse() {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *temp = head;
    struct node *nxt = NULL;
    while(current!=NULL) {
        nxt = current->next;
        current->next = prev;
        prev = current;
        current = nxt;
    }
    head = prev;
    tail = temp;
}
int main() {
    int A[] = {1,2,3,4,5,6};
    int n= 6;
    createLL(A, n);
    display();
    printf("\n");
    reverse();
    display();

    return 0;
}