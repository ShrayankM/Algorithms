#include<cstdio>
using namespace std;
double taylor(int x,int N){
    static double P = 1, F = 1;
    if(N==0)
        return 1;
    else{
        double r = taylor(x,N-1);
        P = P * x; F = F * N;
        return (r + P/F);
    }
}
double taylorH(int x,int N){
    static double S = 1;
    if(N == 0)
        return S;
    else{
        S = 1 + (double)x/N * S;
        return taylorH(x,N-1);
    }
}
double taylorI(int x,int N){
    double S = 1, P = 1, F = 1;
    for(int i=1;i<=N;i++){
        P = P * x; F = F * i;
        S = S + P/F;
    }
    return S;
}
int main(){
    int N = 20, x = 3;
    printf("%f\n",taylor(x,N));
    printf("%f\n",taylorH(x,N));
    printf("%f\n",taylorI(x,N));
    return 0;
}