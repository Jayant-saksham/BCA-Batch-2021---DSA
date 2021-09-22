#include<stdio.h>
int main() {
    printf("%d", 2%5);
    return 0;
}

// 5%1 -> 0
// 5%2 -> 1
// 5%3 -> 2
// 5%4 -> 1
// 5%5 -> 0
// 5%6 -> 5
