//TODO: Find connected components and check for cycles in them using BFS
//? https://codeforces.com/problemset/problem/977/E
//* If the degree of all vertices in a connected component is greater than 2 
//* then the connected componenet has a cycle in them.

#include<bits/stdc++.h> 
using namespace std; 

const int Nmax = 2 * 1E5 + 2;
vector<int> edges[Nmax];
int parent[Nmax], treesize[Nmax];
set<int> components;
bool visited[Nmax];

void init(int n) {
    for (int i = 1; i <=n; i++) {
        visited[i] = false;
        parent[i] = i;
        components.insert(i);
        treesize[i] = 0;
    }
}

int findparent(int a) {
    while (a != parent[a])
        a = parent[a];
    return a;
}

void unionfind(int a, int b) {
    a = findparent(a);
    b = findparent(b);

    if (a == b)
        return;
    
    if (treesize[a] < treesize[b]) {
        components.erase(a);
        components.insert(b);
        parent[a] = b;
    }
    else {
        components.erase(b);
        components.insert(a);
        parent[b] = a;

        if (treesize[a] == treesize[b])
            treesize[a]++;
    }
}

bool bfs(int start) {
    int nodes = 0, degree_two = 0;
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()) {
        int node = q.front(); q.pop();
        nodes++;
        if (edges[node].size() == 2)
            degree_two++;
        for (int n: edges[node]) {
            if (!visited[n]) {
                visited[n] = true;
                q.push(n);
            }
        }
    }

    if (nodes == degree_two)
        return true;
    return false;
}

int main(){ 
    ios_base::sync_with_stdio(false);cin.tie(NULL); 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
    #endif 

    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        unionfind(u, v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    // cout << components.size();
    set<int>::iterator itr; int cycles = 0;
    for (itr = components.begin(); itr != components.end(); itr++) {
            if (bfs(*itr))
                cycles++;
    }

    cout << cycles;
    return 0; 
} 