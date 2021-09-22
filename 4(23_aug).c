#include<stdio.h>
int findMax(int A[], int n) {
    int max = A[0];
    for(int i=1;i<n;i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    return max;
}
int findMin(int A[], int n) {
    int min = A[0];
    for(int i=1;i<n;i++){
        if(A[i]<min){
            min = A[i];
        }
    }
    return min;
}
int findSecondLargest(int A[], int n) {
    int max = findMax(A, n);
    int secondLargest = -10000000;
    for(int i=0;i<n;i++) {  
        if(A[i]!=max && A[i]>secondLargest) {
            secondLargest = A[i];
        }
    }
    return secondLargest;
}
int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    int secondlargest = findSecondLargest(A, n);
    printf("%d", secondlargest);
    return 0;
}