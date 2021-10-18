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
void delteFromLast() {
    if(head == NULL) {
        return;
    }
    struct node *r = head;
    struct node *k = NULL;
    while(r->next!=NULL) {
        k = r;
        r = r->next;
    }
    tail = k;
    tail->next = NULL;
    free(r);
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
void addLast(int x) {
    struct node *temp = createNode(x);
    tail->next = temp;
    tail = temp;
}
int top() {
    if(head == NULL) {
        return -1;
    }
    return tail->data;
}
void createStack(int A[] ,int n) {
    struct node *ptr = createNode(A[0]);
    head = ptr;
    tail = ptr;
    for(int i=1;i<n;i++) {
        struct node *temp = createNode(A[i]);
        tail->next = temp;
        tail = temp;
    }
}
void menu() {
    printf("Enter 1: Add data\n");
    printf("Enter 2: Delete\n");
    printf("Enter 3: Display\n");
    printf("Enter 4: Top element\n");
    printf("Enter 5: Size\n");
}
int main() {
    int A[] = {1,2,3,4,5};
    createStack(A, 5);
    while(1) {
        menu();
        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == 1) {
            int x;
            printf("Enter data to be added : ");
            scanf("%d", &x);
            addLast(x);
        }
        else if(choice == 2) {
            delteFromLast();
        }
        else if(choice == 3) {
            display();
        }
        else if(choice == 4) {
            printf("%d", top());
        }
        else if(choice == 5) {
            printf("%d", size());
        }
        else {
            break;
        }
    }
    return 0;
}