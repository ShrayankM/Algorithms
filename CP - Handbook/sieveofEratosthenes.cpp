#include<bits/stdc++.h>
using namespace std;

const int Nmax = 100001;
bool isPrime[Nmax];

void displayPrime(int N){
    for(int i = 2; i <= N; i++)
        if(isPrime[i])
            printf("%d ", i);
    printf("\n");
}

void sieve(int N){
    for(int i = 2; i <= N; i++)
        isPrime[i] = true;
    
    for(int i = 2; i <= (N/2); i++){
        if(!isPrime[i])
            continue;
        for(int j = i * 2; j <= N; j = j + i)
            isPrime[j] = false;
    }
    displayPrime(N);
}

int main(){

    int N;
    printf("Enter the Number: ");
    scanf("%d", &N);

    sieve(N);
    return 0;
}