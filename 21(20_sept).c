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
        tail = temp;
    }
}
// Microsoft
void deleteDuplicates() {
    struct node *current = head;
    struct node*next_next = NULL;
    if(current == NULL) {
        return;
    }
    while(current->next!=NULL) {
        if(current->data == current->next->data) {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }    
        else {
            current = current->next;
        }   
    }
}
int isEven(int x) {
    if(x%2==0) {
        return 1;
    }
    return 0;
}
void displayRec(struct node *ptr) {
    if(ptr==NULL) {
        return;
    }
    printf("%d ", ptr->data);
    displayRec(ptr->next);
}
struct node* oddEven() {
    struct node *oddHead = NULL;
    struct node *evenhead = NULL;
    struct node *oddTail = NULL;
    struct node *evenTail = NULL;
    struct node *ptr = head;
    while(ptr!=NULL) {
        if(isEven(ptr->data)) {
            struct node *temp = createNode(ptr->data);
            if(evenhead == NULL) {
                evenhead = temp;
                evenTail = temp;
            }
            else {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        else {
            struct node *temp = createNode(ptr->data);
            if(oddHead == NULL) {
                oddHead = temp;
                oddTail = temp;
            }
            else {
                oddTail->next = temp;
                oddTail = temp;
            }
        }
        ptr = ptr->next;
    }
    oddTail->next = evenhead;
    return oddHead;
}
void display() {
    struct node *ptr = head;
    while(ptr!=NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
int main() {
    int A[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(A)/sizeof(A[0]);
    createLL(A, n);

    struct node *ptr = oddEven();
    displayRec(ptr);
    return 0;
}