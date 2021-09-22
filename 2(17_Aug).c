// #include<stdio.h>
// int main() {
//     int n;
//     printf("Enter n : ");
//     scanf("%d", &n);
//     int A[n];
//     for(int i=0;i<n;i++){
//         scanf("%d", &A[i]);
//     }
//     int key;
//     printf("Enter key : ");
//     scanf("%d", &key);
//     int found = -1;
//     for(int i=0;i<n;i++){
//         if(A[i] == key){
//             found = i;
//             break;
//         }
//     }
//     if(found == -1){
//         printf("not found");
//     }
//     else{
//         printf("Found at %d location", found);
//     }
//     return 0;
// }
#include<stdio.h>
int factorial(int n){
    int ans = 1;
    for(int i=n;i>=1;i--){
        int multiply = i*ans;
        ans = multiply;
    }
    return ans;
}

int factorial2(int n){
    int ans = 1;
    for(int i=1;i<=n;i++){
        int multiply = i*ans;
        ans = multiply;
    }
    return ans;
}

int isPrime(int n){
    int mukut = 1;
    for(int  i=2;i<=(n-1);i++){
        if(n%i==0){
            mukut = 0;
            break;
        }
    }      
    return mukut;
}

int isPrime2(int n){
    int mukut = 1;
    for(int i=(n-1);i>=2;i--){
        if(n%i==0){
            mukut = 0;
            break;
        }
    }
    return mukut;
}

int sumOfDigit(int n){
    int ans = 0;
    while(n>0){
        int last = n%10;
        int add = last + ans;
        ans = add;
        n = n/10;
    }
    return ans;
}

int apnaPower(int a, int b){
    int ans=1;
    for(int i=0;i<b;i++){
        ans = ans*a;
    }
    return ans;
}
int main(){
    int n;
    // printf("Enter a number : ");
    // scanf("%d", &n);
    printf("%d", apnaPower(3,1));
    return 0;
}
