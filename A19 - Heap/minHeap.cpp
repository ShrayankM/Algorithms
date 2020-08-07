#include<bits/stdc++.h>
using namespace std;

void heapify(int A[], int parent, int N){
    int Small = parent;
    int L = 2 * parent; int R = 2 * parent + 1;

    if(L < N && A[L] < A[Small])
        Small = L;
    
    if(R < N && A[R] < A[Small])
        Small = R;
    
    if(Small != parent){
        swap(A[Small], A[parent]);
        heapify(A, Small, N);
    }
         
}

int main(){

    int A[] = {-1, 45, 6, 23, 8, 19, 16, 45, 23, 1, 9};
    int N = sizeof(A)/sizeof(int);

    for(int i = (N - 1)/2; i >= 1; i--)
        heapify(A, i, N);
    
    for(int i = 1; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}