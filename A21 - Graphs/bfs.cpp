#include<bits/stdc++.h>
using namespace std;

const int Nmax = 100;
int visited[Nmax];

int main(){
    freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<int> adj[n + 1];
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int startnode = 1;
    visited[startnode] = 1;
    queue<int>Q; Q.push(startnode);
    while(!Q.empty()){
        int node = Q.front(); Q.pop();
        cout << node << " ";
        vector<int> temp = adj[node];
        for(int i = 0; i < (int)temp.size(); i++){
            if(!visited[temp[i]]){
                Q.push(temp[i]);
                visited[temp[i]] = 1;
            }
        } 
    }
    cout << "\n";
    return 0;
}