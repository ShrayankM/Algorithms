#include<bits/stdc++.h>
using namespace std;

const int Nmax = 100;
int Rank[Nmax], parent[Nmax];

void initialize(){
    for(int i = 1; i <= Nmax; i++)
        Rank[i] = 0;
    for(int i = 1; i <= Nmax; i++)
        parent[i] = i;
}

int find(int x){
    while(x != parent[x])
        x = parent[x];
    return x;
}

bool isSameset(int a, int b){
    return find(a) == find(b);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(Rank[a] > Rank[b])
        parent[b] = a;
    else{
        parent[a] = b;
        if(Rank[a] == Rank[b])
            Rank[b]++;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    priority_queue<tuple<int, int, int>>Q;
    for(int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        Q.push(make_tuple(-w, a, b));
    }
    initialize(); int costT = 0;
    vector<pair<int, int>>Tree;
    while(!Q.empty()){
        int a, b, w;
        tie(w, a, b) = Q.top(); Q.pop();
        if(!isSameset(a, b)){
            costT += (w * -1);
            Tree.push_back(make_pair(a, b));
            merge(a, b);
        }
    }
    for(auto e: Tree)
        cout << e.first << " " << e.second << "\n";
    cout << "COST:" << costT << "\n";
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