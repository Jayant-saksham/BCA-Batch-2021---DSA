#include<stdio.h>
void display(int A[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d ", A[i]);
    }
}
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int A[], int n) {
    for(int j=0;j<n-1;j++) {
        for(int i=0;i<n-j;i++) {
            if(A[i]>A[i+1]) {
                swap(&A[i], &A[i+1]);
            }
        }
    }
}
void selectionSort(int A[], int n) {
    int minimumIdx;
    for(int i=0;i<n-1;i++){
        minimumIdx = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[minimumIdx]){
                minimumIdx = j;
            }
        }
        swap(&A[minimumIdx], &A[i]);
    }
}
int main() {
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int A[n];
    for(int i=0;i<n;i++) {
        scanf("%d", &A[i]);
    }
    selectionSort(A, n);
    display(A, n);
    return 0;
}

// 22 -> 12