#include<cstdio>
using namespace std;

const int N = 9;
int A[] = {2,-7, 10, 3, -1, 19, -20, 23, 17};
int U[N], S[N];

void Update(int x, int y,int val){
    U[x] += val; U[y+1] -= val;
}

void UpdateArray(){
    S[0] = U[0]; A[0] += S[0];
    for(int i = 1;i < N; i++){
        S[i] = S[i - 1] + U[i];
        A[i] += S[i];
    }
}
int main(){
    Update(3,7,5);
    Update(4,8,2);
    Update(2,6,1);
    UpdateArray();

    for(int i = 0; i < N; i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
}