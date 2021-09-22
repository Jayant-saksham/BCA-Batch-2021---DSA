#include<stdio.h>
int binarySearchIterative(int A[], int n, int key, int low, int high) {
    while(high>=low) {
        int mid = low + (high-low)/2;
        if(A[mid] == key) {
            return mid;
        }
        else if(A[mid]<key) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}
int floorValue(int A[], int n, int key, int low, int high) {
    int ans = -1;
    while(high>=low) {
        int mid = low + (high-low)/2;
        if(A[mid] == key) {
            return A[mid];
        }
        else if(A[mid]<key) {
            ans = A[mid];
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}
int minimumIndex(int A[], int n, int low, int high) {
    if(high>=low) {
        int mid = low + (high-low)/2;
        int next = (mid+1)%n;
        int prev = (mid-1+n)%n;
        if(A[mid]<A[next] && A[mid]<A[prev]) {
            return mid;
        }
        else if(A[mid]>A[high]) {
            int idx = minimumIndex(A,n,mid+1,high);
            return idx;
        }
    }
    return -1;
}
int searchInPartial(int A[], int n, int key, int low, int high) {
    int miniIndex = minimumIndex(A,n,0,n-1);
    if(A[miniIndex-1]>key) {
        return binarySearchIterative(A,n,key,low,miniIndex-1);
    }
    return binarySearchIterative(A,n,key,miniIndex,high);
}
int main() {
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d", &A[i]);
    }
    int key;
    scanf("%d", &key);
    printf("%d", floorValue(A,n,key, 0, n-1));
    return 0;
}