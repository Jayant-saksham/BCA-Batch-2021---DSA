#include<stdio.h>
int binarySearchHelper(int A[], int n, int key, int low, int high) {
    if(high>=low) {
        int mid = low + (high-low)/2;
        if(A[mid] == key) {
            return mid;
        }
        else if(A[mid]<key) {
            int idx = binarySearchHelper(A,n,key, mid+1, high);
            return idx;
        }
        else {
            int idx = binarySearchHelper(A, n, key, low, mid-1);
            return idx;
        }
    }
    return -1;
}

int binarySearchReverseSortedHelper(int A[], int n, int key, int low, int high) {
    if(high>=low) {
        int mid = low + (high-low)/2;
        if(A[mid] == key) {
            return mid;
        }    
        else if(A[mid]<key) {
            int idx = binarySearchReverseSortedHelper(A, n, key, low, mid-1);
            return idx;
        }
        else {
            int idx = binarySearchReverseSortedHelper(A, n, key,mid+1, high);
            return idx;
        }
    }
    return -1;
}

int binarySearchReverseSorted(int A[], int n, int key) {
    return binarySearchReverseSortedHelper(A, n, key, 0, n-1);
}

int binarySearch(int A[], int n, int key) {
    return binarySearchHelper(A,n,key,0,n-1);
}

int BSOrdernotknown(int A[], int n, int key) {
    if(A[0]>A[n-1]){
        return binarySearchReverseSorted(A,n, key);
    }
    return binarySearch(A,n,key);
}

int BSfirstindexHelper(int A[], int n, int key, int low, int high) {
    if(high>=low){
        int mid = low + (high-low)/2;
        if(A[mid] == key && A[mid-1]<key) {
            return mid;
        }
        else if(A[mid]<key) {
            return BSfirstindexHelper(A,n,key,mid+1, high);
        }
        else{
            return BSfirstindexHelper(A,n,key,low,mid-1);
        }
    }
    return -1;
}
int BSfirstindex(int A[], int n, int key) { 
    return BSfirstindexHelper(A,n,key,0, n-1);
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
    printf("%d", BSfirstindex(A,n,key));
    return 0;
}