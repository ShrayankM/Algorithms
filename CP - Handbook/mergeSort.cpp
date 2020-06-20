#include<cstdio>
using namespace std;

void merge(int A[], int L, int M, int H){
    int* LA = new int[M - L + 1];
    int* RA = new int[H - M];

    for(int i = L, j = 0; i <= M; i++, j++)
        LA[j] = A[i];

    for(int i = M + 1, j = 0; i <= H; i++, j++)
        RA[j] = A[i];
    
    int K = L; int i, j;
    for(i = 0, j = 0; (i < (M - L + 1) && j < (H - M)); ){
        if(LA[i] >= RA[j]){
            A[K++] = RA[j];
            j++;
        }
        else if(LA[i] < RA[j]){
            A[K++] = LA[i];
            i++;
        }
    }
    while(i < (M - L + 1))
        A[K++] = LA[i++];
    
    while(j < (H - M))
        A[K++] = RA[j++];
}

void mergeSort(int A[], int L, int H){
        if(L == H)
            return;
        int M = (L + H)/2;
        mergeSort(A, L, M);
        mergeSort(A, M + 1, H);
        merge(A, L, M, H);
}

void display(int A[], int N){
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    int A[] = {45, 4, 67, 12, 78, 3, 2, 16, 21, 79, 78, 45, 64, 55};
    int N = sizeof(A)/sizeof(int);
    mergeSort(A, 0, N - 1);
    display(A, N);
    return 0;
}