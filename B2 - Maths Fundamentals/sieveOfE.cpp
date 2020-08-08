#include<cstdio>
using namespace std;
const int NMAX = 100000;
bool isPrime[NMAX];

void sof(int N){
    for(int i = 2; i <= N; i++)
        isPrime[i] = true;
    for(int i = 2; i <= (N/2); i++){
        if(isPrime[i]){
            for(int j = i * 2; j <= N; j = j + i)
                isPrime[j] = false;
        }
    }
}
int main(){
    int N = 1000;
    sof(N);
    for(int i = 2; i <= N; i++)
        if(isPrime[i])
            printf("%d ",i);
    printf("\n");
    return 0;
}