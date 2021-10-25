#include<stdio.h>
void sum() {
    int a,b;
    printf("Enter a : ");
    scanf("%d", &a);
    printf("Enter b : ");
    scanf("%d", &b);
    int A[a][b];
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            int x;
            printf("Enter data : ");
            scanf("%d", &x);
            A[i][j] = x;
        }
    }

    int B[a][b];
    printf("Now enter new matrix : \n");
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            int x;
            printf("Enter data : ");
            scanf("%d", &x);
            B[i][j] = x;
        }
    }
    int C[a][b];
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            C[i][j] = 0;
        }
    }

    for(int i=0;i<a;i++) {
        for(int j=0;j<b;i++) {
            int sum = A[i][j] + B[i][j];
            C[i][j] += sum;
        }
    }

    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
}
void muliplication() {
    int a,b;
    printf("Enter a : ");
    scanf("%d", &a);
    printf("Enter b : ");
    scanf("%d", &b);
    int A[a][b];
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            int x;
            printf("Enter data : ");
            scanf("%d", &x);
            A[i][j] = x;
        }
    }

    int c,d;
    printf("Enter c : ");
    scanf("%d", &c);
    printf("Enter d : ");
    scanf("%d", &d);
    int B[c][d];
    for(int i=0;i<c;i++) {
        for(int j=0;j<d;j++) {
            int x;
            printf("Enter data : ");
            scanf("%d", &x);
            B[i][j] = x;
        }
    }
    if(b==c) {
        int C[a][d];
        for(int i=0;i<a;i++) {
            for(int j=0;j<d;j++) {
                C[i][j] = 0;
            }
        }    

        for(int i=0;i<a;i++) {
            for(int j=0;j<d;j++) {
                for(int k=0;k<b;k++) {
                    int m = A[i][k] * B[k][j];
                    C[i][j] += m;
                }
            }
        }   


        for(int i=0;i<a;i++) {
            for(int j=0;j<d;j++) {
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }

    }
    else {
        printf("Not possible");
    }

}
int main() {
    
    // sum();
    muliplication();
    return 0;
}