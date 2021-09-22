#include<stdio.h>
int fibonacci(int n) {
    if(n<=0){
        return -1;
    }
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int sum = fibonacci(n-1) + fibonacci(n-2);
    return sum;
}
int maxArray(int A[], int n) {
    if(n==1){
        return A[0];
    }
    int ans1 = maxArray(A, n-1);
    int ans2 = A[n-1];
    if(ans1>ans2){
        return ans1;
    }
    return ans2;
}
int minArray(int A[], int n) {
    if(n==1){
        return A[0];
    }
    int ans1 =minArray(A, n-1);
    int ans2 = A[n-1];
    if(ans1>ans2){
        return ans2;
    }
    return ans1;
}

void displayArray(int A[],int n) {
    if(n==1){
        printf("%d\t", A[0]);
        return;
    }
    displayArray(A,n-1);
    printf("%d\t", A[n-1]);
}
void displayReverseArray(int A[], int n) {
    if(n==1){
        printf("%d\t", A[0]);
        return;
    }
    printf("%d\t", A[n-1]);
    displayReverseArray(A, n-1);
}

int main() {
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    displayReverseArray(A, n);
    return 0;
}