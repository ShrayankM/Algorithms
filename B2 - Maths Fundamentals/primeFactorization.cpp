#include<cstdio>
using namespace std;

int f[100], expo[100], len;
void createFactors(int N){
    int d = 2;
    while(N > 1){
        int K = 0;
        while(N % d == 0){
            N = N / d;
            K++;
        }
        if(K > 0){
            len++;
            f[len] = d; expo[len] = K;
        }
        d++;
    }
}
int main(){
    int N = 100;
    createFactors(N);
    for(int i = 1; i <= len; i++)
        printf("Factor:%d Exponent:%d \n",f[i], expo[i]);
    return 0;
}