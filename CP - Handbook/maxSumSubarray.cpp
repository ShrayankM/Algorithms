#include<cstdio>
#include<algorithm>
using namespace std;

int Msum(int A[], int N){
    int sum = 0, best = 0;
    for(int i = 0; i < N; i++){
        sum = 0;
        for(int j = i; j < N; j++){
            sum += A[j];
            best = max(sum, best);
        }
    }
    return best;
}

int MsumO(int A[], int N){
    int sum = 0, best = 0;
    for(int i = 0; i < N; i++){
        sum = max(A[i], sum + A[i]);
        best = max(sum, best);
    }
    return best;
}
int main(){
    int A[] = {-1, 2, 4, -3, 5, 2, -5, 2};
    int N = 8;
    printf("TC O(N^2) %d\n",Msum(A, N));

    printf("TC O(N) %d\n",MsumO(A, N));
    return 0;
}