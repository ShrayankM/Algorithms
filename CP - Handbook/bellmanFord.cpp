#include<bits/stdc++.h>
using namespace std;

const int N = 5;
const int INF = INT32_MAX - 1;

void displayGraph(vector<pair<int, int>> A[N + 1]){
    for(int i = 1; i <= N; i++){
        cout << "Node: " << i << "\t" << "\\";
        vector<pair<int, int>> T = A[i];
        for(int j = 0; j < (int)T.size(); j++)
            cout << T[j].first << " ";
        cout << "\n";
    } 
}

int main(){
    freopen("graphs_input.txt", "r", stdin);
    int M; cin >> M;
    vector<pair<int, int>> adj[N + 1];
    for(int i = 0; i < M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        //adj[b].push_back(make_pair(a, w));
    }

    //displayGraph(adj);
    /**
     * TODO Starting Node is 1 */
    vector<int> distance(N + 1);
    distance[1] = 0;
    for(int i = 2; i <= N; i++)
        distance[i] = INF;

    for(int i = 1; i < N; i++){
        for(int node = 1; node <= N; node++){
            vector<pair<int, int>> T = adj[node];
            for(int j = 0; j < (int)T.size(); j++){
                distance[T[j].first] = min(distance[T[j].first], distance[node] + T[j].second);
            }
        }
    }

    for(int i = 1; i <= N; i++)
        cout << distance[i] << " ";


    return 0;
}

/** 
 * TODO input for graphs_input.txt
 * */

/**
 * ! 7
 * ? 1 2 2
 * ? 1 3 3
 * ? 1 4 7
 * ? 3 4 -2
 * ? 2 4 3
 * ? 2 5 2
 * ? 4 5 2 
 * */