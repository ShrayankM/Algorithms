#include<bits/stdc++.h>
using namespace std;

const int N = 5;
const int INF = __INT32_MAX__ - 1;
bool visited[N + 1];
int distance_node[N + 1];

int main(){
    freopen("graphs_input.txt", "r", stdin);
    int M; cin >> M;

    vector<pair<int, int>> adj[N + 1];
    for(int i = 0; i < M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    distance_node[1] = 0;
    for(int i = 2; i <= N; i++)
        distance_node[i] = INF;

    priority_queue<pair<int, int>>Q;
    /**
     * ? Starting Node is 1 */
    Q.push(make_pair(0, 1));
    while(!Q.empty()){
        int node = Q.top().second; Q.pop();
        if(visited[node])
           continue;
        visited[node] = true;
        vector<pair<int, int>> T = adj[node];
        for(int i = 0; i < (int)T.size(); i++){
            int b = T[i].first; int w = T[i].second;
            distance_node[b] = min(distance_node[b], distance_node[node] + w);
            Q.push(make_pair(-distance_node[b], b));
        }
    }

    for(int i = 1; i <= N; i++)
        cout << distance_node[i] << " ";
    cout << "\n";
    return 0;
}

/** 
 * TODO Input For the graphs_input.txt */
/** 
 * * 6
 * * 1 5 1
 * * 1 4 9
 * * 1 2 5
 * * 2 3 2
 * * 3 4 6
 * * 4 5 2 */