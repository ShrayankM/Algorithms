#include<cstdio>
#include<vector>
using namespace std;
vector<int>M(100,-1);
int fib(int N){
    if(N == 0)
        return 0;
    if(N == 1)
        return 1;
    return fib(N-1) + fib(N - 2);
}

int fibN(int N){
    if(N == 0){
        M[0] = 0;
        return 0;
    }
    if(N == 1){
        M[1] = 1;
        return 1;
    }
    if(M[N-1] == -1)
        M[N-1] = fibN(N-1);
    if(M[N-2] == -1)
        M[N-2] = fibN(N-2);
    return M[N-1] + M[N-2];
}
int main(){
    int N = 7;
    printf("%d\n",fib(N));
    printf("%d\n",fibN(N));
    return 0;
}