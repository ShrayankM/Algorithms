/** *
 * ? A successor is a directed graph such that the outdegree of every node is
 * ? one. i.e.(only one outgoing edge for every node)
 * TODO
 * 1) Check if cycle present 2)Find length of cycle if present
 * */

#include<bits/stdc++.h>
using namespace std;

int succ(int x, map<int, int>E){
    if(E[x] == 0)
        return -1;
    return E[x];
}

bool cycle(map<int, int>E, int startnode){
    int a = succ(startnode, E); int b = succ(succ(startnode, E), E);
    while(a != b){
        a = succ(a, E);
        b = succ(succ(b, E), E);
        if(b == -1)
            return false;
    }
    a = startnode;
    while(a != b){
        a = succ(a, E);
        b = succ(b, E);
    }
    cout << "FirstNode in cycle is:" << a << "\n";
    int length = 1;
    a = succ(a, E);
    while(a != b){
        a = succ(a, E);
        length++;
    }
    cout << "Length of cycle is: " << length << "\n";
    return true;
}

int main(){

    freopen("input.txt", "r", stdin);
    int m;
    cin >> m;
    map<int, int>E;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        E[a] = b;
    }
    int startnode = 1;
    if(cycle(E, startnode))
        cout << "Cycle Present" << "\n";
    else
        cout << "No Cycle" << "\n";
    return 0;
}