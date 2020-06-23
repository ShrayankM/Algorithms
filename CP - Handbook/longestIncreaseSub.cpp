#include<bits/stdc++.h>
using namespace std;

int A[] = {6, 2, 5, 1, 7, 4, 8, 3, 9};
int N = 9;
const int Nmax = 101;
int L[Nmax];

int main(){
    for(int i = 0; i < N; i++){
        L[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(A[j] < A[i]){
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }
    printf("%d\n", *max_element(L, L + N));
    return 0;
}