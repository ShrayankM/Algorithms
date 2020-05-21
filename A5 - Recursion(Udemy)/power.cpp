#include<cstdio>
using namespace std;
int powerN(int x,int N){
    if(N == 1)
        return x;
    else
        return powerN(x,N-1) * x;
}

int powerR(int x,int N){
    if(N == 1)
        return x;
    else{
        if(N%2 == 0)
            return powerR(x*x,N/2);
        else
            return powerR(x*x,(N - 1)/2) * x;
    }
}
int main(){
    int x = 2, N = 5;
    printf("%d\n",powerN(x,N));
    printf("%d\n",powerR(x,N));
}