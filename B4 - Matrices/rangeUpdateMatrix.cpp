#include<cstdio>
using namespace std;

const int Nmax = 1000; int N, M;
int Matrix[Nmax][Nmax], U[Nmax][Nmax];
int PMatrix[Nmax][Nmax];

void displayM(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}
//Brute Force O(N * M)
void updateMatrix(int R1, int C1, int R2, int C2, int V){
    for(int i = R1; i <= R2; i++)
        for(int j = C1; j <= C2; j++)
            Matrix[i][j] += V;
}
//TC O(1)
void update(int R1, int C1, int R2, int C2, int V){
    U[R1][C1] += V; U[R1][C2 + 1] -= V;
    U[R2 + 1][C1] -= V; U[R2 + 1][C2 + 1] += V;
}

void buildPartialSums(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            PMatrix[i][j] = PMatrix[i][j - 1] + PMatrix[i - 1][j] - PMatrix[i - 1][j - 1]
                          + U[i][j];
        }
    }
}
void updateMain(){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            Matrix[i][j] += PMatrix[i][j];
}
int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            scanf("%d", &Matrix[i][j]);

    int Q; scanf("%d", &Q);
    int R1, C1, R2, C2, V;
    for(int i = 1; i <= Q; i++){
         scanf("%d %d %d %d %d", &R1, &C1, &R2, &C2, &V);
         update(R1, C1, R2, C2, V);
    }
    buildPartialSums();
    updateMain();
    displayM();
    return 0;
}
//Input File:
/*6 6
1 7 12 10 1 0
11 7 -10 1 3 13
-2 9 -5 2 4 7
4 14 -9 3 13 -6
-7 -8 -9 12 6 4
2 -13 10 11 8 7
2
1 3 3 5 10
3 4 6 6 5*/