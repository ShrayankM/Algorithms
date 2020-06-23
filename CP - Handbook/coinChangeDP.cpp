#include<cstdio>
#include<algorithm>
using namespace std;

int C[] = {1, 3, 4};
const int Nmax = 101;
int value[Nmax]; bool check[Nmax];
const int INF = __INT32_MAX__ - 1;

int solveM(int N){
    if(N == 0)
        return 0;
    if(N < 0)
        return INF;
    if(check[N])
        return value[N];
    int best = INF;
    for(int i = 0; i < 3; i++){
        best = min(best, solveM(N - C[i]) + 1);
    }
    check[N] = true;
    value[N] = best;
    return best;
}

int solve(int N){
    if(N == 0)
        return 0;
    if(N < 0)
        return INF;
    int best = INF;
    for(int i = 0; i < 3; i++)
        best = min(solve(N - C[i]) + 1, best);
    return best;
}

int main(){
    int N = 50;
    printf("%d\n", solve(N)); //Very Slow
    printf("%d\n", solveM(N)); // Very Efficient
    return 0;
}