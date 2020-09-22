#include<bits/stdc++.h>
using namespace std;

const int Nmax = 10;

struct UnionFind{
    int *parent;
    int *treesize;
    set<int> components;
    UnionFind() {
        parent = new int[Nmax + 1];
        treesize = new int[Nmax + 1];

        for (int i = 1; i <= Nmax; i++) {
            parent[i] = i;
            components.insert(i);
            treesize[i] = 0;
        }
    }

    int findparent(int a) {
        while (a != parent[a])
            a = parent[a];
        return parent[a];
    }

    void unionfind(int a, int b) {
        a = findparent(a);
        b = findparent(b);

        if (a == b)
            return;
        
        if (treesize[a] < treesize[b]) {
            components.erase(b);
            components.insert(a);
            parent[b] = a;
        }
        else {
            parent[a] = b;
            components.erase(a);
            components.insert(b);
            if (treesize[a] == treesize[b])
                treesize[a]++;
        }
    }
};

int main(){

    UnionFind u;
    cout << "Total Components: " << u.components.size() << "\n";
    u.unionfind(1, 2);
    cout << "Total Components: " << u.components.size() << "\n";
    u.unionfind(3, 4);
    u.unionfind(4, 5);
    cout << "Total Components: " << u.components.size() << "\n";
    u.unionfind(6, 7);
    cout << "Total Components: " << u.components.size() << "\n";
    u.unionfind(3, 2);
    u.unionfind(6, 1);
    cout << "Total Components: " << u.components.size() << "\n";
    return 0;
}