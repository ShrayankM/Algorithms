#include<cstdio>
using namespace std;
int fact(int N){
    if(N ==0 || N == 1)
        return 1;
    else
        return fact(N-1) * N;
}
int main(){
    int N = 5;
    printf("%d\n",fact(N));
    return 0;
}