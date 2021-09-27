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
void createLL(int A[], int n) {
    struct node *ptr = createNode(A[0]);
    head = ptr;
    tail = ptr;
    for(int i=1;i<n;i++) {
        struct node *temp = createNode(A[i]);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
int length(struct node *starting) {
    struct node *ptr = starting;
    int count = 0;
    while(ptr!=NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}
struct node *intersectionLL1(struct node *head1, struct node *head2) {
    if(head1 == NULL || head2 == NULL) {
        return NULL;
    }
    int headlen1 = length(head1);
    int headlen2 = length(head2);
    int diff = headlen1-headlen2;
    if(diff<0) {
        diff = diff*(-1);
    }
    struct node *p = head1;
    struct node *q = head2;
    for(int i=0;i<diff;i++) {
        if(headlen1>headlen2) {
            p=p->next;
        }
        else {
            q = q->next;
        }
    }
    while(p!=NULL && q!=NULL) {
        p = p->next;
        q = q->next;
        if(p == q) {
            return q;
        }
    }
    return NULL;
}
struct node *intersectionLL2(struct node *head1, struct node *head2) {
    if(head1 == NULL || head2 == NULL) {
        return NULL;
    }
    struct node *p = head1;
    struct node *q = head2;
    while(p!=q) {
        if(p==NULL) {
            p = head2;
        }
        else {
            p = p->next;
        }
        if(q==NULL) {
            q = head1;
        }
        else {
            q = q->next;
        }
        if(q==NULL && p==NULL) {
            return NULL;
        }
    }
    return q;    
}

int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    return 0;
}