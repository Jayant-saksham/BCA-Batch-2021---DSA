#include<stdio.h>

int main() {
    // int r,c;
    // printf("Enter row : ");
    // scanf("%d", &r);
    // printf("Enter column : ");
    // scanf("%d", &c);
    // int A[r][c];
    // Method - 1
    // for(int i=0;i<r;i++) {
    //     for(int j=0;j<c;j++) {
    //         int data;
    //         printf("Enter data : ");
    //         scanf("%d", &data);
    //         A[i][j] = data;            
    //     }
    // }


    // Method - 2
    // for(int j=0;j<c;j++) {
    //     for(int i=0;i<r;i++) {
    //         int data;
    //         printf("Enter data : ");
    //         scanf("%d", &data);
    //         A[i][j] = data;
    //     }
    // }

    // printf("Displaying matrix : \n");
    // for(int i=0;i<r;i++) {
    //     for(int j=0;j<c;j++) {
    //         printf("%d ", A[i][j]);
    //     }
    //     printf("\n");
    // }

    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int A[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int data;
            printf("Enter data : ");
            scanf("%d", &data);
            A[i][j] = data;
        }
    }

    // Sum
    // int sum = 0;
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         sum += A[i][j];
    //     }
    // }
    // printf("Sum is %d", sum);


    // int sum = 0;
    // for(int i=0;i<n;i++) {
    //     for(int j=i;j<n;j++) {
    //         sum += A[i][j];
    //     }
    // }
    // printf("Sum is %d", sum);

    int sum = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=(n-i-1);j++) {
            sum += A[i][j];
        }
    }
    printf("Sum is %d", sum);

    return 0;
}