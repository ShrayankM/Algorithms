#include<bits/stdc++.h>
using namespace std;

void countsort(int A[], int N){
    int m = 0;
    for(int i = 0; i < N; i++)
        m = max(m, A[i]);
    int* B = new int[m + 1];

    for(int i = 0; i < N; i++)
        B[A[i]]++;
    
    int j = 0;
    for(int i = 0; i <= m; i++){
        if(B[i] > 0){
            A[j++] = i;
            B[i]--;
        }
    }
}

int main(){

    int A[] = {23, 21, 12, 4, 13, 8, 76, 45, 1, 5};
    int N = sizeof(A)/sizeof(int);

    countsort(A, N);
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}