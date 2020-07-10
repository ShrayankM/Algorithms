/** 
 * TODO Find the number of paths from given node a to node b 
 * TODO in a directed acyclic graph 
 * */

/** 
 * ? paths(x) is the function that gives number of paths from a to x 
 * */

#include<bits/stdc++.h>
using namespace std;

const int Nmax = 100;
vector<int>TS;

int paths(int x, int a, vector<int> r[]){
    static int T[Nmax];
    if(x == a)
        return 1;
    if(T[x] != 0)
        return T[x];
    int path_count = 0;
    for(int i = 0; i < (int)r[x].size(); i++)
        path_count += paths(r[x][i], a, r);
    T[x] = path_count;
    return path_count;
}

int main(){
    freopen("input.txt", "r", stdin);
    int m;
    cin >> m;
    vector<int> adj[Nmax]; vector<int> r[Nmax];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        r[b].push_back(a);
    }
    int b = 7; int a = 1;
    cout << paths(b, a, r) << "\n";
    return 0;
}

/**
 * ? Edges(m) = 7 directed edge from a to b (1 2) 
 * */

/** 
 * * 7
 * * 1 2 
 * * 1 4 
 * * 2 3
 * * 2 6 
 * * 3 6
 * * 4 5 
 * * 5 2 
 * */

/**
 * * 8
 * * 1 2
 * * 2 3
 * * 3 6
 * * 4 1
 * * 4 5
 * * 5 2
 * * 5 3
 * * 5 6 
 * */

/** 
 * * 10 
 * * 1 2
 * * 1 3
 * * 2 4
 * * 2 5
 * * 3 6
 * * 4 7
 * * 5 4
 * * 5 7
 * * 6 5
 * * 6 7 
 * */