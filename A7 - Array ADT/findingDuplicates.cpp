#include<bits/stdc++.h>
using namespace std;

void find_duplicateHash(int A[], int N){
    int M = *max_element(A, A + N);
    int* T = new int[M + 1];

    for(int i = 0; i < N; i++)
        T[A[i]]++;
    
    for(int i = 1; i <= M; i++)
        if(T[i] > 1)
            printf("%d ", i);
    printf("\n");
}

void find_duplicateSort(int A[], int N){
    int lastduplicate = 0;
    for(int i = 0; i < N - 1; i++){
        if(A[i] == A[i + 1] && lastduplicate != A[i]){
            printf("%d ", A[i]);
            lastduplicate = A[i];
        }
    }
    printf("\n");
}

void find_duplicate(int A[], int N){
    for(int i = 0; i < N; i++){
        int count = 0;
        if(A[i] != -1){
            for(int j = i + 1; j < N; j++){
                if(A[i] == A[j]){
                    count++; A[j] = -1;
                }
            }
            if(count > 0)
                printf("%d ", A[i]);
        }
    }
    printf("\n");
}

int main(){
    int A[] = {1, 1, 4, 5, 4, 4, 5, 6, 7, 10, 11, 10, 1, 6, 8, 9, 13, 15, 16};
    int N = sizeof(A)/sizeof(int);

    //find_duplicate(A, N); //TC = O(N ^ 2)
    sort(A, A + N);
    find_duplicateSort(A, N); //TC = O(NlogN)

    find_duplicateHash(A, N); //TC = O(N) but space consuming
    return 0;
}