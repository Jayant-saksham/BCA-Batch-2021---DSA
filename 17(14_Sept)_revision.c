#include<stdio.h>
int linearSearch(int A[], int n, int key) {
    for(int i=0;i<n;i++){
        if(A[i]==key){
            return i;
        }
    }
    return -1;
}
long long int factorial(int n){
    long long int f = n;
    for(int i=(n-1);i>=1;i--){
        f = f*i;
    }
    return f;
}
int main() {

    return 0;
}