#include<bits/stdc++.h>
using namespace std;

const int N = 5;
const int INF = INT32_MAX - 1;

int main(){
    freopen("graphs_input.txt", "r", stdin);
    int M; cin >> M;
    vector<tuple<int, int, int>> adj;
    for(int i = 0; i < M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj.push_back(make_tuple(a, b, w));
    }

    vector<int> distance(N + 1);
    distance[1] = 0;
    for(int i = 2; i <= N; i++)
        distance[i] = INF;

    for(int i = 1; i < N; i++){
        for(int j = 0; j < (int)adj.size(); j++){
            int a, b, w;
            tie(a, b, w) = adj[j];
            distance[b] = min(distance[b], distance[a] + w);
        }
    }

    for(int i = 1; i <= N; i++)
        cout << distance[i] << " ";
    cout << "\n";
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