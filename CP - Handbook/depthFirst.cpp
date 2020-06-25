#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int Nmax = 100;
vector<int> AList[Nmax];
bool visited[Nmax];
int N = 5, M = 5;

void list_display(vector<int> A[Nmax], int N){
    for(int i = 1; i <= N; i++){
        vector<int>T = A[i];
        printf("%d: ", i);
        for(int j = 0; j < (int)T.size(); j++)
            printf("%d ", T[j]);
        printf("\n");
    }
}

void clearvisited(){
    for(int i = 0; i < Nmax; i++)
        visited[i] = false;
}

void dfs(int N){
    if(visited[N])
        return;
    visited[N] = true;
    printf("%d ", N);
    for(int i = 0; i < (int)AList[N].size(); i++)
        dfs(AList[N][i]);
}

void bfs(int N){
    visited[N] = true;
    queue<int>Q;
    Q.push(N);
    while(!Q.empty()){
        int P = Q.front(); Q.pop();
        printf("%d ", P);
        for(int i = 0; i < (int)AList[P].size(); i++){
            int node = AList[P][i];
            if(!visited[node]){
                Q.push(node); visited[node] = true;
            }
        }
    }
}

int main(){
    int AMatrix[Nmax][Nmax] = {{0, 0, 0, 0, 0, 0},
                               {0, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 1},
                               {0, 0, 1, 0, 0, 1},
                               {0, 1, 0, 0, 0, 0},
                               {0, 0, 1, 1, 0, 0}};

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(AMatrix[i][j] == 1)
                AList[i].push_back(j);
    list_display(AList, N);
    printf("DFS Traversal: ");
    dfs(1);
    printf("\n");

    clearvisited();

    printf("BFS Traversal: ");
    bfs(1);
    printf("\n");
    return 0;
}