// #include<stdio.h>
// int main() {
//     int a = 10;
//     float b = 3.14;
//     char ch = 'A';
//     char name[] = "DIMPLE"; 
//     int arr[] = {10,20,30,40};
//     return 0;
// }


// #include<stdio.h>
// int main() {
//     int A[5] = {10,20,30,40,50};
//     int n = 4;
//     for(int i = 0;i<=n;i++){
//         printf("%d\n", A[i]);
//     }
//     return 0;
// }



#include<stdio.h>
int main() {
    int n;
    printf("Enter your length : ");
    scanf("%d", &n);
    int A[n];
    for(int i=0;i<n;i++) {
        scanf("%d", &A[i]);
    }
    printf("Enter what to found : ");
    int key;
    scanf("%d", &key);
    int location = -1;
    for(int i=0;i<n;i++){
        if(A[i] == key){
            location = i;
            break;
        }
    }
    if(location == -1){
        printf("not found");
    }
    else{
        printf("Found at %d location", location);
    }
    return 0;
}