#include<bits/stdc++.h>
using namespace std;

const int Nmax = 101;
int parent[Nmax], size[Nmax];

void initialize(){
    for(int i = 1; i < Nmax; i++){
        parent[i] = i;
        size[i] = 1;
    }
}


int find(int x){
    if(parent[x] == x)
        return x;
    return find(parent[x]);
}

bool same(int a, int b){
    if(find(a) == find(b))
        return true;
    return false;
}

void unite(int a, int b){
    int _ap = find(a);
    int _bp = find(b);

    if(size[_ap] >= size[_bp]){
        size[_ap] += size[_bp];
        parent[_bp] = _ap;
    }
    else{
        size[_bp] += size[_ap];
        parent[_ap] = _bp;
    }
}

int main(){

    freopen("input.txt", "r", stdin);
    int m;
    cin >> m;
    priority_queue<tuple<int, int, int>>E;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        E.push(make_tuple(-w, a, b));
    }

    initialize();
    int cost = 0;
    while(!E.empty()){
        int a, b, w;
        tie(w, a, b) = E.top(); E.pop();
        if(!same(a, b)){
            cost = cost + (w * -1);
            unite(a, b);
        }
    }

    cout << cost << "\n";
    return 0;
}

/*8
1 2 3
1 5 5
2 5 6
2 3 5
5 6 2
3 6 3
3 4 9
6 4 7*/