#include<stdio.h>
#include<cstring>
int isPalindrome(char A[], int n) {
    int flag = 1;
    int start = 0;
    int end = n-1;
    while(end>=start) {
        if(A[start]!=A[end]){
            flag = 0;
            break;
        }
        start++;
        end--;
    }
    return flag;
}

int isCapital(char c){
    if(c>=65 && c<=90){
        return 1;
    }
    return 0;
}

int main() {
    // char ch[] = "This";
    // printf("%s", ch);

    // char A[50];
    // printf("%s", A);


    // char A[50];
    // printf("Enter a string : ");
    // scanf("%s", A);
    // printf("%s", A);


    // char ch[50];
    // printf("Enter a string : ");
    // gets(ch);
    // puts(ch);

    // char ch[] = "Hello";
    // char A[50];
    // strcpy(A, ch);
    // puts(A);

    // char A[50];
    // gets(A);
    // char B[50];
    // gets(B);
    // puts(strcat(A, B));


    // char A[50];
    // gets(A);
    // char B[50];
    // gets(B);
    // if(strcmp(A,B)==0) {
    //     printf("Equal");
    // }
    // else{
    //     printf("Not equal");
    // }


    // char A[50];
    // gets(A);
    // int count = 0;
    // for(int i=0;A[i]!='\0';i++){
    //     count = count + 1;
    // }
    // printf("%d", count);


    char A[50];
    gets(A);
    for(int i=0;A[i]!='\0';i++){
        if(isCapital(A[i])){
            printf("%c", A[i]);
        }
    }
    
    return 0;
}