#include<cstdio>
using namespace std;
int sumofN(int N){
    if(N == 1)
        return 1;
    else
        return sumofN(N - 1) + N;
}
int main(){
    int N = 10;
    printf("%d\n",sumofN(N));
    return 0;
}