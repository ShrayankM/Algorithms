#include<bits/stdc++.h>
using namespace std;

int C[] = {1, 3, 4};
const int Nmax = 101;
int value[Nmax]; bool check[Nmax];
int F[Nmax];
const int INF = __INT32_MAX__ - 1;

int totalWays(int N){
    if(N == 0)
        return 1;
    if(N < 0)
        return 0;
    if(check[N])
        return value[N];
    int ways = 0;
    for(int i = 0; i < 3; i++)
        ways += totalWays(N - C[i]);
    check[N] = true;
    value[N] = ways;
    return ways;
}

int main(){
    int N = 100;
    printf("%d\n", totalWays(N));
    return 0;
}