#include<cstdio>
using namespace std;
int fact(int N){
    if(N == 1 || N == 0)
        return 1;
    else
        return fact(N-1)*N;
}
int CN(int N,int R){
    return fact(N)/(fact(R) * fact(N - R));
}
int CR(int N,int R){
    if(N == R || R == 0)
        return 1;
    else
        return CR(N-1,R-1) + CR(N-1,R);
}
int main(){
    printf("%d\n",CN(5,3));
    printf("%d\n",CR(5,3));
    return 0;
}