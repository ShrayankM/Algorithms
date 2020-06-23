#include<bits/stdc++.h>
using namespace std;

const int Nmax = 101;
int N = 5;
int A[6][6] = {{0, 0, 0, 0, 0, 0},
               {0, 3, 7, 9, 2, 7},
               {0, 9, 8, 3, 5, 5},
               {0, 1, 7, 9, 8, 5},
               {0, 3, 8, 6, 4, 10},
               {0 ,6, 3, 9, 7, 8}};
int sum[Nmax][Nmax];

void display(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }
}
int main(){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + A[i][j];
    
    display();
    printf("%d\n", sum[N][N]);
    return 0;
}