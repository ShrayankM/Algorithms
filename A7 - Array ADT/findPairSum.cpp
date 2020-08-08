#include<bits/stdc++.h>
using namespace std;

const int sum = 20; //Finding all pairs such that their sum is 20

void find_pairs_Hash(int A[], int N){
    int* T = new int[sum];
    for(int i = 0; i < N; i++){
        int diff = sum - A[i];
        if(diff > 0 && T[diff] == 1)
            printf("%d + %d = %d\n", A[i], sum - A[i], sum);
        T[diff] = 1;
    }
}

void find_pairs_Sorted(int A[], int N){
    sort(A, A + N);
    for(int i = 0, j = N - 1; i < j; ){
        if(A[i] + A[j] == sum){
            printf("%d + %d = %d\n", A[i], A[j], sum);
            i++; j--;
        }
        else if(A[i] + A[j] > sum)
            j--;
        else
            i++;
    }
}   

void find_pairs(int A[], int N){
    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++)
            if(A[i] + A[j] == sum)
                printf("%d + %d = %d\n", A[i], A[j], sum);
}

int main(){
    int A[] = {1, 1, 4, 5, 4, 4, 5, 6, 7, 10, 11, 10, 1, 6, 8, 9, 13, 15, 16};
    int N = sizeof(A)/sizeof(int);

    find_pairs(A, N); // Brute Force TC = O(N ^ 2)

    printf("------------------------------------------------------------\n");

    find_pairs_Hash(A, N); // TC = O(N) but uses a lot of space 

    printf("------------------------------------------------------------\n");

    find_pairs_Sorted(A, N); // TC = O(NlogN) + O(N)
    return 0;
}