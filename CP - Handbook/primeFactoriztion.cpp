#include<bits/stdc++.h>
using namespace std;

const int Nmax = 100;
int F[Nmax], E[Nmax];

void displayFactors(int L){
    for(int i = 1; i <= L; i++)
        printf("Factor: %d, Exponent: %d\n", F[i], E[i]);
}

void findFactorization(int N){
    int L = 0; int d = 2;
    while(N > 1 && d <= sqrt(N)){
        int k = 0;
        while(N%d == 0){
            k++; N = N/d;
        }
        if(k > 0){
            L++;
            F[L] = d; E[L] = k;
        }
        d++;
    }
    if(N > 1){
        L++; F[L] = N; E[L] = 1;
    }
    displayFactors(L);
}

int main(){

    int N;
    printf("Enter the Number: ");
    scanf("%d", &N);
    findFactorization(N);
    return 0;
}