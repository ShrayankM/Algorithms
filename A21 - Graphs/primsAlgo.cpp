#include<bits/stdc++.h>
using namespace std;

const int NMAX = 100;
int cost[NMAX][NMAX];
int near[NMAX];
vector<pair<int, int>>T;

void initialize(){
    for(int i = 1; i < NMAX; i++)
        near[i] = INT32_MAX - 1;
    
    for(int i = 1; i < NMAX; i++)
        for(int j = 1; j < NMAX; j++)
            cost[i][j] = INT32_MAX - 1;
    
}

void spanningTree(int n){
    int costT = 0;
    int u, v; int min = INT32_MAX - 1;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(min > cost[i][j]){
                min = cost[i][j];
                u = i; v = j;
            }
        }
    }
    //cout << min << " " << u << " " << v << "\n";
    T.push_back(make_pair(u, v));
    costT += min;
    near[u] = 0, near[v] = 0;
    for(int i = 1; i <= n; i++){
        if(near[i] != 0)
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
    }

    for(int i = 1; i < n - 1; i++){
        min = INT32_MAX - 1; int j;
        for(int k = 1; k <= n; k++){
            if(near[k] != 0 && cost[k][near[k]] < min){
                min = cost[k][near[k]];
                j = k;
            }
        }
        T.push_back(make_pair(j, near[j]));
        costT += min;
        near[j] = 0;
        for(int k = 1; k <= n; k++){
            if(near[k] != 0 && cost[k][j] < cost[k][near[k]])
                near[k] = j;
        }
    }
    for(auto e:T)
        cout << e.first << " " << e.second << "\n";
    cout << "COST:" << costT << "\n";
}

int main(){
    freopen("input.txt", "r", stdin);
    int n, m; 
    cin >> n >> m;
    initialize();
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
        cost[v][u] = w;
    }
    spanningTree(n);
    return 0;
}

/*
9 14
1 2 4
1 8 8
2 8 11
2 3 8
3 9 2
3 4 7
3 6 4
4 5 9
4 6 14
5 6 10
6 7 2
7 9 6
7 8 1
8 9 7
*/