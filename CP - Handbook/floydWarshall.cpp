#include<bits/stdc++.h>
using namespace std;

const int Nmax = 101;
const int INF = INT32_MAX - 1;
int M[Nmax][Nmax];
long long distance_node[Nmax][Nmax];

void display(int A[Nmax][Nmax], int N){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
}

int main(){

    freopen("graphs_input.txt", "r", stdin);
    int N; cin >> N;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> M[i][j];
        
    //display(M, N);
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j)
                distance_node[i][j] = 0;
            else if(M[i][j] == 0)
                distance_node[i][j] = INF;
            else
                distance_node[i][j] = M[i][j];
        }
    }

    //display(distance_node, N);

    for(int node = 1; node <= N; node++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                distance_node[i][j] = min(distance_node[i][j], distance_node[i][node] + distance_node[node][j]);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            cout << distance_node[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

/** 
 * TODO Input for the program */
/** 
 * ? 5
 * ? 0 5 0 9 1 
 * ? 5 0 2 0 0
 * ? 0 2 0 7 0
 * ? 9 0 7 0 2
 * ? 1 0 0 2 0 */