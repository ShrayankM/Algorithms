#include<bits/stdc++.h>
using namespace std;

const int Nmax = 101;
bitset<Nmax> M[Nmax];

void neighbours(vector<int> adj[], int n){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < (int)adj[i].size(); j++){
            int a = i; int b = adj[i][j];
            M[a][b] = 1;
        }
    }
}

void reach(vector<int> adj[], int n){
    for(int i = 1; i <= n; i++){
        M[i][i] = 1;
        for(int j = 0; j < (int)adj[i].size(); j++){
            int a = i; int b = adj[i][j];
            M[a] = M[a] | M[b];
        }
        cout << "Reach of " << i << " " << M[i].count() << "\n";
    }
}

int main(){

    freopen("input.txt", "r", stdin);
    int m, n;
    cin >> m >> n;
    vector<int> adj[Nmax];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    neighbours(adj, n);
    reach(adj, n);
    return 0;
}

/*
6 5
1 2 
1 3
2 4
2 5
3 4
4 5*/