#include<stdio.h>
void toh(char src, char destination, char intermediate, int n) {
    if(n<=0) {
        return;
    }
    else if(n==1) {
        printf("Move %c to %c\n", src, destination);
        return;
    }
    toh(src,intermediate, destination, n-1);
    printf("Move %c to %c\n", src, destination);
    toh(intermediate, destination, src, n-1);
}

int firstIndex(int A[], int key, int n, int idx) {
    if(A[idx] == key) {
        return idx;
    }
    if(idx == n) {
        return -1;
    }
    return firstIndex(A, key, n, idx+1);    
}

int lastIndex(int A[], int n, int key, int idx) {
    if(idx<0) {
        return -1;
    }
    if(A[idx] == key) {
        return idx;
    }
    int lastIdx = lastIndex(A, n, key, idx-1);
    return lastIdx;
}

int main() {
    printf("Enter n : ");
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0;i<n;i++) {
        scanf("%d", &A[i]);
    }
    int key;
    printf("Enter key : ");
    scanf("%d", &key);
    int ans = lastIndex(A, n, key, n-1);
    printf("%d", ans);
    return 0;
}