#include<cstdio>
#include<algorithm>
using namespace std;

const int Nmax = 10001; int N, M;
int A[Nmax][Nmax], UpSum[Nmax][Nmax], PMatrix[Nmax][Nmax];


int maxSumSubArray(int A[], int N){
    int ans = A[1], sum = 0;
    for(int i = 1; i <= N; i++){
        sum += A[i];
        ans = max(ans, sum);
        sum = sum < 0 ? 0:sum;
    }
    return sum;
}
//TC O((N ^ 2) * M)
int maxSumSubMatrix(){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            UpSum[i][j] = UpSum[i - 1][j] + A[i][j];
    
    int ans = A[1][1]; int V[Nmax];
    for(int r1 = 1; r1 <= N; r1++){
        for(int r2 = r1; r2 <= N; r2++){
            for(int i = 1; i <= M; i++)
                V[i] = UpSum[r2][i] - UpSum[r1 - 1][i];
            ans = max(ans, maxSumSubArray(V, M));
        }   
    }
    return ans;
}

int sumSubMatrix(int R1, int C1, int R2, int C2){
    return PMatrix[R2][C2] - PMatrix[R1 - 1][C2] - PMatrix[R2][C1 - 1] + PMatrix[R1 - 1][C1 - 1];
}
//TC O((N * M) ^ 2)
int brutemaxSum(){
    int ans = A[1][1];
    for(int r1 = 1; r1 <= N; r1++){
        for(int c1 = 1; c1 <= M; c1++){
            for(int r2 = r1; r2 <= N; r2++){
                for(int c2 = c1; c2 <= M; c2++){
                    ans = max(ans, sumSubMatrix(r1, c1, r2, c2));
                }
            }
        }
    }
    return ans;
}

void buildPartialSums(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            PMatrix[i][j] = PMatrix[i][j - 1] + PMatrix[i - 1][j] - PMatrix[i - 1][j - 1] + A[i][j];
        }
    }
}
int main(){
    freopen("input.txt", "r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            scanf("%d", &A[i][j]);
    
    buildPartialSums();
    printf("Maximum sum of submatrix: %d\n",brutemaxSum());
    printf("Maximum sum of submatrix: %d\n",maxSumSubMatrix());
    return 0;
}