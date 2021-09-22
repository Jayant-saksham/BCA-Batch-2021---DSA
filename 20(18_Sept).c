#include<stdio.h>
#include<cstdlib>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;
struct node *createNode(int x) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(head == NULL) {
        head = ptr;
        tail = ptr;
        ptr->prev = NULL;
    }
    ptr->data = x;
    ptr->next = NULL;
    return ptr;
}
void createLL(int A[], int n) {
    struct node *ptr = createNode(A[0]);
    for(int i=1;i<n;i++) {
        struct node *temp = createNode(A[i]);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void display() {
    struct node *ptr = head;
    printf("NULL");
    while(ptr!=NULL) {
        printf("<-%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
void displayReverse() {
    struct node *ptr = tail;
    printf("NULL");
    while(ptr!=NULL) {
        printf("<-%d->", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL");
}
void deleteFromFirst() {
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    ptr->next = NULL;
    free(ptr);
}
void deleteFromLast() {
    struct node *ptr = tail;
    tail = tail->prev;
    tail->next = NULL;
    ptr->prev = NULL;
    free(ptr);
}
int lenght() {
    int len = 0;
    struct node *ptr=head;
    while(ptr!=NULL) {
        len++;
        ptr = ptr->next;
    }
    return len;
}
int lenghtRecursion(struct node *ptr) {
    if(ptr==NULL) {
        return 0;
    }
    return 1 + lenghtRecursion(ptr->next);
}
void deleteFromAnyIndex(int idx) {
    if(idx == 0) {
        deleteFromFirst();
    }
    else if(idx == lenght() -1) {
        deleteFromLast();
    }
    else {
        struct node *k = NULL;
        struct node *r = head;
        for(int i=0;i<idx;i++) {
            k = r;
            r = r->next;
        }
        k->next = r->next;
        r->next->prev = k;
        r->next = NULL;
        r->prev = NULL;
        free(r);
    }
}
void insertFirst(int x) {
    struct node *ptr = createNode(x);
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
}
void insertLast(int x) {
    struct node *ptr = createNode(x);
    ptr->next = NULL;
    ptr->prev = tail;
    tail->next = ptr;
    tail = ptr;
}
void insertIndex(int idx, int x) {
    if(idx == 0) {
        insertFirst(x);
    }
    else if(idx == lenght() - 1) {
        insertLast(x);
    }
    else {
        struct node *k = NULL;
        struct node *r = head;
        for(int i=0;i<idx;i++) {
            k = r;
            r = r->next;
        }
        struct node *ptr = createNode(x);
        k->next = ptr;
        ptr->next = r;
        r->prev = ptr;
        ptr->prev = k;

    }
}
int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    createLL(A, n);
    insertIndex(3, 1000);
    display();
    printf("\n %d", lenght());
    return 0;
}