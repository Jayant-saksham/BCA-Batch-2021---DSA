#include<stdio.h>
#include<cstdlib>
struct Stack {
    int top;
    int capacity;
    int *A;
};
struct Stack *stack = NULL;
struct Stack *createStack(int capacity) {
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->A = (int *)malloc(sizeof(int) * stack->capacity);
    return stack;
}
int isEmpty() {
    if(stack->top == -1) {
        return 1;
    }
    return 0;
}
int isFull() {
    if(stack->top == (stack->capacity - 1)) {
        return 1;
    }
    return 0;
}
void push(int x) {
    if(isFull()) {
        return;
    }
    stack->top++;
    stack->A[stack->top] = x; 
}
void pop() {
    if(isEmpty()) {
        return;
    }
    stack->A[stack->top] = 0;
    stack->top--;
}
int peek() {
    if(isEmpty()) {
        return -1;
    }
    return stack->A[stack->top];
}
void display() {
    for(int i=0;i<=stack->top;i++) {
        printf("%d ", stack->A[i]);
    }
}
int main() {
    struct Stack * s = createStack(100);
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    pop();
    pop();
    display();
    return 0;
}