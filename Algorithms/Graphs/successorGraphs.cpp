/** *
 * ? A successor is a directed graph such that the outdegree of every node is
 * ? one. i.e.(only one outgoing edge for every node)
 * TODO Find the successor node from x after taking k steps
 * ! 2 methods 
 * * 1)TC O(k) 
 * * 2) TC O(logk) 
 * */

#include<bits/stdc++.h>
using namespace std;

const int Nmax = 100;
const int U = 100000;
int S[U + 1][Nmax + 1];

int succ(int x, int k, map<int, int> E){
    if(k == 0)
        return x;
    return succ(E[x], k - 1, E);
}

void preprocess(vector<pair<int, int>>ET){
    int index = 1;
    for(int i = 0; i < (int)ET.size(); i++){
        int a = ET[i].first; int b = ET[i].second;
        S[index][a] = b;
    }
    index++;
    for(; index <= U; index++){
        for(int i = 0; i < (int)ET.size(); i++){
            int a = ET[i].first; 
            int h = index/2;
            S[index][a] = S[h][S[h][a]];
        }
    }
}

int succLog(int x, int k){
    if(k == 1)
        return S[k][x];
    return succLog(succLog(x, k/2),k/2); 
}

int main(){

    freopen("input.txt", "r", stdin);
    int m;
    cin >> m;
    vector<pair<int, int>> ET;
    map<int, int>E;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ET.push_back(make_pair(a, b));
        E[a] = b;
    }

    int x = 1; int k = 14;
    /** *
     * ! TC of succ is O(k)
     * ? There is no preprocessing time complexity
     *  */
    cout << succ(x , k, E) << "\n";

    /** *
     * ? Preprocesssing all succ(x, k) values upto U for all k such that k is power of 2 
     * ! TC is O(NlogU) 
     * */

    preprocess(ET);
    /** *
     * ! TC of succLog is O(logk)
     *  */
    cout << succLog(x, k) << "\n";
    return 0;
}


/**
 * ? Edges(m) = 7 directed edge from a to b (1 2) 
 * */

/** 
 * * 7
 * * 1 2 
 * * 2 3
 * * 3 4 
 * * 4 5 
 * * 5 6
 * * 6 4
 * */