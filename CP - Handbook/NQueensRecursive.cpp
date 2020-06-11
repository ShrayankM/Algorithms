#include<cstdio>
using namespace std;

const int Nmax = 1000;
int C[Nmax], D1[Nmax], D2[Nmax]; int count = 0;
int N;
void backTrack(int y){
    if(y == N){
        count++; return;
    }
    for(int x = 0; x < N; x++){
        if(C[x] || D1[x + y] || D2[x - y + N - 1])
            continue;
        C[x] = D1[x + y] = D2[x - y + N - 1] = 1;
        backTrack(y + 1);
        C[x] = D1[x + y] = D2[x - y + N - 1] = 0;
    }
}
int main(){
    N = 14;
    backTrack(0);
    printf("Total Solutions: %d\n",count);
    return 0;
}