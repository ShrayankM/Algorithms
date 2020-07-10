#include<bits/stdc++.h>
using namespace std;

const int Nmax = 1001;
int A[Nmax];
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
    vector<tuple<int, int, int>>E;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        E.push_back(make_tuple(a, b, w));
    }

    initialize();
    int startnode = 1;
    A[startnode] = 1;
    priority_queue<tuple<int, int, int>>Q;
    for(int i = 0; i < (int)E.size(); i++){
        if(get<0>(E[i]) == startnode || get<1>(E[i]) == startnode)
            Q.push(make_tuple(-get<2>(E[i]), get<0>(E[i]), get<1>(E[i])));
    }

    int cost = 0;
    while(!Q.empty()){
        int a, b, w;
        tie(w, a, b) = Q.top(); Q.pop();
        if(!same(a, b)){
            cost = cost + (w * -1);
            if(A[a] == 0){
                A[a] = 1;
                for(int i = 0; i < (int)E.size(); i++){
                    int _a, _b, _w;
                    tie(_a, _b, _w) = E[i];
                    if((_a == a || _b == a))
                        Q.push(make_tuple(-_w, _a, _b));
                }
            }

            if(A[b] == 0){
                A[b] = 1;
                for(int i = 0; i < (int)E.size(); i++){
                    int _a, _b, _w;
                    tie(_a, _b, _w) = E[i];
                    if((_a == b || _b == b))
                        Q.push(make_tuple(-_w, _a, _b));
                }
            } 
            unite(a, b);
        }
    }

    cout << cost << "\n";
    return 0;
}