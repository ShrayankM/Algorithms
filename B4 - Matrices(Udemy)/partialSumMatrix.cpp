#include<cstdio>
using namespace std;

const int Nmax = 1000;
int Matrix[Nmax][Nmax]; int N, M;
int PMatrix[Nmax][Nmax];

//Brute Force O(N * M)
int sumOfsub(int R1, int C1, int R2, int C2){
    int sum = 0;
    for(int i = R1; i <= R2; i++)
        for(int j = C1; j <= C2; j++)
            sum += Matrix[i][j];
    return sum;
}
//TC O(N * M)
void buildPartial(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            PMatrix[i][j] = PMatrix[i][j - 1] + 
                PMatrix[i - 1][j] - PMatrix[i - 1][j - 1] + Matrix[i][j];
        }
    }
}
//TC O(1)
int query(int R1, int C1, int R2, int C2){
    return (PMatrix[R2][C2] - PMatrix[R1 - 1][C2] - PMatrix[R2][C1 - 1] + PMatrix[R1 - 1][C1 - 1]);
}
void displayM(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            scanf("%d", &Matrix[i][j]);
    
    //displayM();
    buildPartial();
    int R1, C1, R2, C2;
    scanf("%d %d %d %d", &R1, &C1, &R2, &C2);
    printf("Brute Force: TC O(N * M) %d\n",sumOfsub(R1, C1, R2, C2));
    printf("Optimal: TC O(1) %d\n",query(R1, C1, R2, C2));

    scanf("%d %d %d %d", &R1, &C1, &R2, &C2);
    printf("Brute Force: TC O(N * M) %d\n",sumOfsub(R1, C1, R2, C2));
    printf("Optimal: TC O(1) %d\n",query(R1, C1, R2, C2));
    return 0;
}

//Input File:
/*
6 6
1 7 12 10 1 0
11 7 -10 1 3 13
-2 9 -5 2 4 7
4 14 -9 3 13 -6
-7 -8 -9 12 6 4
2 -13 10 11 8 7
1 3 3 5 
3 4 6 6*/