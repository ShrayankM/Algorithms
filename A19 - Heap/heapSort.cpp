#include<bits/stdc++.h>
using namespace std;

void heapify(int A[], int parent, int N){
    int Large = parent;
    int L = 2 * parent; int R = 2 * parent + 1;

    if(L < N && A[L] > A[Large])
        Large = L;
    
    if(R < N && A[R] > A[Large])
        Large = R;
    
    if(Large != parent){
        swap(A[Large], A[parent]);
        heapify(A, Large, N);
    }
}

int main(){

    int A[] = {-1, 45, 6, 23, 8, 19, 16, 45, 23, 1, 9};
    int N = sizeof(A)/sizeof(int);

    for(int i = (N - 1)/2; i >= 1; i--)
        heapify(A, i, N);
    
    for(int i = N - 1; i >= 1; i--){
        swap(A[1], A[i]);
        heapify(A, 1, i);
    }

    for(int i = 1; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}