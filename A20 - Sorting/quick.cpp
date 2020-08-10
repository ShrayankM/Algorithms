#include<bits/stdc++.h>
using namespace std;

int partition(int A[], int L, int H){
    int pivot = A[L];
    int i = L, j = H;
    do{
        do{ i++; }while(A[i] <= pivot);
        do{ j--; }while(A[j] > pivot);

        if(i < j)
            swap(A[i], A[j]);
    }while(i < j);
    swap(A[L], A[j]);
    return j;
}

void quicksort(int A[], int L, int H){
    if(L < H){
        int j = partition(A, L, H);
        quicksort(A, L, j);
        quicksort(A, j + 1, H);
    }
}
int main(){

    int A[] = {23, 21, 12, 4, 13, 8, 76, 45, 12, 2, INT32_MAX};
    int N = sizeof(A)/sizeof(int);

    quicksort(A, 0, N - 1);
    for(int i = 0; i < N - 1; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}