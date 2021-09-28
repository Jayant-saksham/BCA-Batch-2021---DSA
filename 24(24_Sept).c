#include<stdio.h>
#include<cstdlib>
struct Stack {
    int topIndex;
    int capacity;
    int *A;
};
struct Stack *stack = NULL;
struct Stack * createStack(int c) {
    stack = (struct Stack *)malloc(sizeof(struct Stack));  
    stack->capacity = c;
    stack->topIndex = -1;
    stack->A = (int *)malloc(sizeof(int) * stack->capacity);
    return stack;
}
int isEmpty() {
    if(stack->topIndex == -1) {
        return 1;
    }
    return 0;
}
int isFull() {
    if(stack->topIndex == (stack->capacity - 1)) {
        return 1;
    }
    return 0;
}
int peek() {
    if(isEmpty()) {
        return -1;
    }
    return stack->A[stack->topIndex];
}
void display() {
    if(isEmpty()) {
        return;
    }
    for(int i=0;i<stack->topIndex;i++) {
        printf("%d ", stack->A[i]);
    }
}
void push(int item) {
    if(isFull()) {
        return;
    }
    stack->topIndex++;
    stack->A[stack->topIndex] = item;
}
void pop() {
    if(isEmpty()) {
        return;
    }
    stack->topIndex = 0;
    stack->topIndex--;
}
int isBalanced(char exp[]) {
    for(int i=0;exp[i]!='\0';i++) {
        if(exp[i] == '(') {
            push(exp[i]);
            continue;
        }
        else if(exp[i] == ')') {
            if(peek() == '(') {
               pop(); 
            }
            else if(isEmpty()) {
                return 0;
            }
        }
    }
    if(isEmpty()) {
        return 1;
    }
    return 0;
}
int main() {
    char exp[] = "(a+b)";
    struct Stack *s = createStack(50);
    printf("%d ", isBalanced(exp));
    return 0;
}