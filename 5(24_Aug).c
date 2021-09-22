#include<stdio.h>
void display(int A[], int n){
    for(int i=0;i<n;i++){
        printf("%d\t", A[i]);
    }
}
void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
void insert(int *A, int *n, int idx, int item){
    if(idx>*n || idx<0){
        printf("Invalid index !");
    }    
    else {
        if(idx == *n){
            A[*n] = item;
        }
        else{
            int temp = A[idx];
            A[idx] = item;
            int c;
            for(int i=idx+1;i<*n;i++){
                swap(&A[i], &temp);
            }
            A[*n] = temp;
        }
        *n++;
    }
}

void deleteIndex(int *A, int *n, int idx){
    if(idx<0 || idx>=*n){
        printf("Invalid index");
    }
    else{
        for(int i=idx+1;i<*n;i++){
            swap(&A[i], &A[i-1]);
        }
        A[*n-1] = 0;
        *n--;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int A[100000];
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    int idx;
    scanf("%d", &idx);
    deleteIndex(A,&n,idx);
    display(A, n);
    return 0;
}