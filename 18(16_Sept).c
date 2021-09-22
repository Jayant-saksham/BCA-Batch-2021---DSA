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
int lengthIt() {
    int count = 0;
    struct node *ptr= head;
    while(ptr!=NULL) {
        count++;
        ptr=ptr->next;
    }
    return count;
}
int lenghRec(struct node *ptr) {
    if(ptr==NULL) {
        return 0;
    }
    return 1 + lenghRec(ptr->next);    
}
void displayLL() {
    struct node *ptr = head;
    while(ptr!=NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}
void deleteFirst() {
    struct node *ptr = head;
    head = head->next;
    ptr->next = NULL;
    free(ptr);
}
void deleteLast() {
    struct node *ptr = head;
    while(ptr->next->next!=NULL) {
        ptr = ptr->next;
    }
    tail = ptr;
    ptr = ptr->next;
    tail->next = NULL;
    free(ptr);
}
void deleteAnyIndex(int idx) {
    if(idx < 0 || idx >=lengthIt()) {
        printf("Invalid Index !");
        return;
    }
    if(idx == 0) {
        deleteFirst();
    }
    else if(idx == (lengthIt() - 1)) {
        deleteLast();
    }
    else {
        struct node *r = head;
        struct node *k = NULL;
        for(int i=0;i<idx;i++) {
            k = r;
            r= r->next;
        }
        k->next = r->next;
        r->next = NULL;
        free(r);
    }
}
struct node *linearSearch(int key) {
    struct node *ptr= head;
    while(ptr!=NULL) {
        if(ptr->data == key) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}
struct node *findMid() {
    struct node *fast = head;
    struct node *slow = head;
    while(fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
void reverseLL() {
    struct node *current = head;
    struct node *prev = NULL;
    struct node *nxt = NULL;
    struct node *temp = head;
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
    int A[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    createLL(A, n);
    displayLL();
    deleteAnyIndex(2);
    printf("\n");
    displayLL();   
    return 0;
}