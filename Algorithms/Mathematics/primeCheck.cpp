#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int N){
    for(int i = 2; i <= sqrt(N); i++){
        if(N%i == 0)
            return false;
    }
    return true;
}

int main(){

    int N;
    printf("Enter the Number: ");
    scanf("%d", &N);
    if(checkPrime(N))
        printf("IS PRIME\n");
    else
        printf("NOT PRIME\n");
    return 0;
}