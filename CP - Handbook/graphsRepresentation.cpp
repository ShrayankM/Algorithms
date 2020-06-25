#include<cstdio>
#include<vector>
using namespace std;

const int Nmax = 100;

void matrix_display(int A[][Nmax], int N){
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(A[i][j] == 1)
                printf("%d %d\n", i, j);
}

void list_display(vector<int> A[Nmax], int N){
    for(int i = 1; i <= N; i++){
        vector<int>T = A[i];
        printf("%d: ", i);
        for(int j = 0; j < (int)T.size(); j++)
            printf("%d ", T[j]);
        printf("\n");
    }
}

void edge_display(vector<pair<int, int>>A, int M){
    for(int i = 0; i < M; i++)
        printf("Edge: %d %d\n",A[i].first, A[i].second);
}
int main(){
    int AMatrix[Nmax][Nmax] = {{0, 0, 0, 0, 0, 0},
                               {0, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1},
                               {0, 0, 1, 0, 0, 1},
                               {0, 1, 0, 0, 0, 0},
                               {0, 0, 1, 1, 0, 0}};
    int N = 5, M = 5;
    //matrix_display(AMatrix, N);
    
    vector<int> AList[N + 1];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(AMatrix[i][j] == 1)
                AList[i].push_back(j);

    list_display(AList, N);

    vector<pair<int, int>>EList;
    EList.push_back(make_pair(1, 2));
    EList.push_back(make_pair(1, 4));
    EList.push_back(make_pair(2, 3));
    EList.push_back(make_pair(2, 5));
    EList.push_back(make_pair(3, 5));

    edge_display(EList, M);
    return 0;
}