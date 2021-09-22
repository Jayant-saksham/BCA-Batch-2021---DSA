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
    if(head == NULL) {
        head = ptr;
        tail = ptr;
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
        tail = temp;
    }
}
int lenghtIt() {
    int count = 0;
    struct node *ptr = head;
    while(ptr!=NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}
int lenghtRec(struct node *ptr) {
    if(ptr==NULL) {
        return 0;
    }
    return 1 + lenghtRec(ptr->next);
}
void displayLL() {
    struct node *ptr = head;
    while(ptr!=NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
void displayRec(struct node *ptr) {
    if(ptr==NULL) {
        return;
    }
    printf("%d ", ptr->data);
    displayRec(ptr->next);
}
struct node *kthFromLast(int k) {
    struct node *slow = head;
    struct node *fast = head;
    for(int i=0;i<k;i++) {
        fast = fast->next;
    }
    while(fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
struct node *findMid() {
    struct node *slow = head;
    struct node *fast = head;
    while(fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
struct node *mergeLL(struct node *head1, struct node *head2) {
    struct node * newLLhead = NULL;
    struct node *newLLtail = NULL;
    while(head1!=NULL && head2!=NULL) {
        if(head1->data<head2->data) {
            struct node *p = createNode(head1->data);
            if(newLLhead == NULL) {
                newLLhead = p;
                newLLtail = p;
            }
            head1 = head1->next;
            newLLtail->next = p;
        }
        else {
            struct node *q = createNode(head2->data);
            if(newLLhead == NULL) {
                newLLhead = q;
                newLLtail = q;
            }
            head2 = head2->next;
            newLLtail->next = q;
        }   
    }
    if(head1!=NULL) {
        while(head1!=NULL) {
            struct node *ptr = createNode(head1->data);
            newLLtail->next = ptr;
            newLLtail = ptr;
        }
    }
    else if(head2!=NULL) {
        while(head2!=NULL) {
            struct node *ptr = createNode(head2->data);
            newLLtail->next = ptr;
            newLLtail = ptr;
        }
    }
    return newLLhead;
}
int main() {
    int A[] = {1,4,8,9,11,12};
    int B[] = {2,3,7};
    struct node *h1 = createLL(A, 6);
    struct node *h2 = createLL(B, 3);
    displayRec(h1);
    // struct node *newLL = mergeLL(h1,h2);
    // displayRec(newLL);
    return 0;
}