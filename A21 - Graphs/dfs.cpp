#include<bits/stdc++.h>
using namespace std;

const int Nmax = 100;
int visited[Nmax];
vector<int> adj[Nmax + 1];

void dfs(int node){
    if(visited[node])
        return;
    visited[node] = 1;
    cout << node << " ";
    vector<int>temp = adj[node];
    for(int i = 0; i < (int)temp.size(); i++)
        dfs(temp[i]);
}

int main(){
    freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int startnode = 1;
    dfs(startnode);
    cout << "\n";
    return 0;
}