#include<stdio.h>
#define V 4
// Adding the edge
void addEdge(int A[V][V], int initial, int final, int isdir) {
    A[initial][final] = 1;
    if(isdir != 1) {
        A[final][initial] = 1;
    }
}

void init(int A[V][V]) {
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            A[i][j] = 0;
        }
    }
}
void printMatrix(int A[V][V]) {
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int A[V][V];
    init(A);
    addEdge(A, 0,2,1);
    addEdge(A, 2,1,1);
    addEdge(A, 1,3,1);
    printMatrix(A);
    return 0;
}