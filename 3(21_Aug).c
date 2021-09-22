#include<stdio.h>
int reverseNumber(int n){
    int rev = 0;
    while(n>0){
        int rem = n%10;
        rev = rev*10 + rem;
        n = n/10;
    }
    return rev;
}
int isPalindrome(int n) {
    int reverse = reverseNumber(n);
    if(n==reverse) {
        return 1;
    }
    return 0;
}
int isArmstrong(int n){
    int ans = 0;
    int temp= n;
    while(n>0){
        int rem = n%10;
        ans = ans + (rem*rem*rem);
        n = n/10;
    }
    if(ans == temp){
        return 1;
    }
    return 0;
}

int main(){
    
    return 0;
}