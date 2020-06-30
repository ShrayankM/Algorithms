#include<bits/stdc++.h>
using namespace std;

const int N = 5;
bool visited[N + 1];
vector<int>TS;
vector<int> adj[N + 1];

void dfs(int node){
    vector<int> T = adj[node];
    visited[node] = true;
    for(int i = 0; i < (int)T.size(); i++){
        if(!visited[T[i]])
            dfs(T[i]);
    }
    TS.push_back(node);
}

int main(){

    freopen("graphs_input.txt", "r", stdin);
    
    int M; cin >> M;

    vector<int> nodes;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        nodes.push_back(a);
    }

    int start_node;
    vector<int> T;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < (int)adj[i].size(); j++){
            T.push_back(adj[i][j]);
        }
    }
    sort(nodes.begin(), nodes.end());
    sort(T.begin(), T.end());
    vector<int> diff(N + 1);
    vector<int> :: iterator it = set_difference(nodes.begin(), nodes.end(), T.begin(), T.end(), diff.begin());

    start_node = *diff.begin();
    cout << start_node << "\n";

    dfs(start_node);
    for(int i = 0; i < (int)TS.size(); i++)
        cout << TS[i] << " ";
    cout << "\n";

    reverse(TS.begin(), TS.end());

    for(int i = 0; i < (int)TS.size(); i++)
        cout << TS[i] << " ";
    cout << "\n";
    return 0;
}

/**
 * TODO Input for program
 */

/**
* ? 7
* ? 4 1
* ? 4 5
* ? 1 2
* ? 2 3
* ? 5 2
* ? 5 3
* ? 3 6 */