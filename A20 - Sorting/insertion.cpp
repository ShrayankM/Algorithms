#include<bits/stdc++.h>
using namespace std;

void insertion(int A[], int N){
    for(int i = 1; i < N; i++){
        int x = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > x){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}
int main(){

    int A[] = {23, 21, 12, 4, 13, 8, 76, 45, 12, 2};
    int N = sizeof(A)/sizeof(int);

    insertion(A, N);
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}