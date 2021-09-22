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
    ptr->next=NULL;
    ptr->data = x;
    return ptr;
}
void createCircularLL(int A[], int n) {
    struct node *ptr = createNode(A[0]);
    if(head == NULL) {
        head = ptr;
        tail = ptr;
    }
    for(int i=1;i<n;i++) {
        struct node *temp = createNode(A[i]);
        tail->next = temp;
        tail = temp;
    }
    tail->next = head;
}
void display() {
    struct node *ptr = head;
    do {
        printf("%d->", ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=head);
}
void addLast(int x) {
    struct node *ptr = createNode(x);
    if(head == NULL) {
        head = ptr;
        tail = ptr;
        tail->next = head;
    }
    else {
        tail->next = ptr;
        tail = ptr;
        tail->next = head;
    }
}
void addFirst(int x) {
    struct node *ptr = createNode(x);
    if(head == NULL) {
        head = ptr;
        tail = ptr;
        tail->next = head;
    }
    else {
        ptr->next = head;
        head = ptr;
        tail->next = head;
    }
}
int length() {
    struct node *ptr = head;
    int count = 0;
    if(head == NULL) {
        return 0;
    }
    do {
        count++;
        ptr=ptr->next;
    }
    while(ptr!=head);
    return count;
}
void addAnyIndex(int idx, int x) {
    if(idx<0 || idx>=length()) {
        return;
    }
    else if(idx == 0) {
        addFirst(x);
    }
    else if(idx == length() - 1) {
        addLast(x);
    }
    else {
        struct node *ptr = createNode(x);
        struct node *r = head;
        struct node *k = NULL;
        for(int i=0;i<idx;i++) {
            k = r;
            r = r->next;
        }
        k->next = ptr;
        ptr->next = r;
    }
}

int main() {
    int A[] = {1,2,3,4,5,6};
    int n = 6;
    createCircularLL(A, n);
    addLast(10);
    addFirst(0);
    display();
    return 0;
}