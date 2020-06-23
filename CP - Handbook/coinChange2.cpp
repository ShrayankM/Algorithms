#include<bits/stdc++.h>
using namespace std;

int C[] = {1, 3, 4};
const int Nmax = 101;
int value[Nmax]; bool check[Nmax];
int F[Nmax];
const int INF = __INT32_MAX__ - 1;

int solve(int N){
    if(N == 0)
        return 0;
    if(N < 0)
        return INF;
    if(check[N])
        return value[N];
    int best = INF;
    for(int i = 0; i < 3; i++){
        //best = min(solve(N - C[i]) + 1, best);
        if(best > solve(N - C[i]) + 1){
            F[N] = C[i];
            best = solve(N - C[i]) + 1;
        }
    }
    check[N] = true;
    value[N] = best;
    return best;
}

void display(int N){
    printf("[ ");
    while(N > 0){
        printf("%d ", F[N]);
        N = N - F[N];
    }

    printf("]\n");
}

int main(){
    int N = 5;
    printf("Total Coins:%d ", solve(N));
    display(N);
    return 0;
}