#include<cstdio>
using namespace std;
const int N = 8;
int A[] = {7, -2, 3, 9, -11, 5, 1, -3};
int S[N];

void buildPartialSums(){
    S[0] = A[0];
    for(int i = 1; i < N; i++)
        S[i] = S[i - 1] + A[i];
}

int Query(int x, int y){
    return S[y] - S[x - 1];
}
int main(){
    buildPartialSums();
    for(int i = 0; i < N; i++)
        for(int j = i; j < N; j++)
            printf("%d ",Query(i,j));
    printf("\n");
    return 0;
}