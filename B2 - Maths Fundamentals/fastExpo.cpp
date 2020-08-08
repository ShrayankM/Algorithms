#include<cstdio>
using namespace std;

const int MOD = 1000000007;

int fastExpo(int A, int N,int MOD){
    if(N == 0)
        return 1;
    if(N == 1)
        return A;
    if(N % 2 == 0)
        return fastExpo((1LL * A * A) % MOD, N/2, MOD);
    return (fastExpo(A, N-1,MOD) * A * 1LL) % MOD;
}
int main(){
    int A = 2, N = 100;
    printf("%d ",fastExpo(A,N,MOD));
    return 0;
}