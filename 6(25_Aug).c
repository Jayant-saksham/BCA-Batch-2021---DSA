#include<stdio.h>
void printIncreasing(int n) {
    if(n<=0) {
        return;
    }
    printIncreasing(n-1);
    printf("%d\t", n);
}
void printDecreasing(int n) {
    if(n<=0) {
        return;
    }
    printf("%d\t", n);
    printDecreasing(n-1);
}
void printDI(int n) {
    if(n<=0) {
        return;
    }
    printf("%d\t", n);
    printDI(n-1);
    printf("%d\t", n);
}
int power(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int ans = power(a, b-1);
    ans = ans * a;
    return ans;
}
int factorial(int n) {
    if(n==0 || n==1) {
        return 1;
    }
    int ans = factorial(n-1); 
    ans = ans * n;
    return ans;
}

int main() {
    int a,b;
    scanf("%d", &a);
    scanf("%d", &b);
    int ans = power(a, b);
    printf("%d", ans);
    return 0;
}