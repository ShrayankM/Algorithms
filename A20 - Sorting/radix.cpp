#include<bits/stdc++.h>
using namespace std;

void radixsort(int A[], int N, int size){
    vector<int> B[10]; int t = 10, k = 1;
    for(int p = 2; p <= N; p = p * 2){
        for(int i = 0; i < N; i++){
            int pos = (A[i]/k)%t;
            B[pos].push_back(A[i]);
        }
        k = k * 10; int j = 0;
        for(int i = 0; i < 10; i++){
            vector<int>temp = B[i];
            for(auto c: temp)
                A[j++] = c;
            B[i].clear();
        }
    }
}

int main(){

    int A[] = {156, 23, 78, 789, 34, 56, 65, 1, 8, 12, 654, 319, 231};
    int N = sizeof(A)/sizeof(int);

    int m = 0;
    for(int i = 0; i < N; i++)
        m = max(m, A[i]);
    
    int size = 0;
    while(m > 0){
        size++;
        m = m/10;
    }
    radixsort(A, N, size);
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}