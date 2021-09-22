#include<stdio.h>
int firstIndexBS(int A[], int n, int key, int low, int high) {
    if(high>=low) {
        int mid = low + (high-low)/2;
        if(A[mid] == key && A[(mid-1+n)%n]<key) {
            return mid;
        }
        else if(A[mid]<key) {
            int idx = firstIndexBS(A, n, key, mid+1, high);
            return idx;
        }
        else {
            int idx = firstIndexBS(A,n, key, low, mid-1);
            return idx;
        }
    }
    return -1;
}

int lastIndexBS(int A[], int n, int key, int low, int high) {
    if(high>=low) {
        int mid = low + (high-low)/2;
        if(A[mid] == key && A[(mid+1)%n]>key) {
            return mid;
        }
        else if(A[mid]>key) {
            int idx = lastIndexBS(A, n, key, low, mid-1);
            return idx;
        }
        else {
            int idx = lastIndexBS(A, n, key, mid+1, high);
            return idx;
        }
    }
    return -1;
}
// Twitter
int countOccurence(int A[], int n, int key) {
    int li = lastIndexBS(A,n,key, 0, n-1);
    int fi = firstIndexBS(A,n,key,0, n-1);
    int ans = li - fi + 1;
    return ans;
}
// Facebook
int countRotationforsort(int A[], int n, int low, int high) {
    if(high>=low) {
        int mid = low + (high-low)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(A[mid]<A[next] && A[mid]<A[prev]) {
            return mid;
        }
        else if(A[mid]>A[high]) {
            int idx = countRotationforsort(A,n,mid+1, high);
            return idx;
        }
    }
    return -1;
}
int main() {
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    printf("%d", countRotationforsort(A,n,0, n-1));
    return 0;
}