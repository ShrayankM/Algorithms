#include<bits/stdc++.h>
using namespace std;

const int Nmax = 10001;
vector<int> adj[Nmax];
int visited[Nmax];
int pos[Nmax];
vector<int>TS;

void dfs(int node){
    visited[node] = 1;
    vector<int> T = adj[node];
    for(int i = 0; i < (int)T.size(); i++){
        if(!visited[T[i]])
            dfs(T[i]);
    }
    TS.push_back(node);
}

int main(){

    freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
    }

    for(int node = 0; node < n; node++){
        if(!visited[node])
            dfs(node);
    }
    reverse(TS.begin(), TS.end());
    for(int i = 0; i < (int)TS.size(); i++){
        pos[TS[i]] = i;
    }
    bool flag = false;
    for(int i = 0; i < n; i++){
        vector<int> T = adj[i];
        for(int j = 0; j < (int)T.size(); j++){
            if(pos[i] > pos[j])
                flag = true;
        }
    }

    if(flag)
        printf("Cycle Detected.\n");
    else
        printf("Cycle Not Detected.\n");
    /*for(int i = 0; i < (int)TS.size(); i++)
        printf("%d ", TS[i]);
    printf("\n");*/
    return 0;
}

/**
 * ? No Cycle Input 
 * */
/*
6 6
2 3
3 1
4 1
4 0
5 0
5 2
*/

/**
 * ? Cycle Input 
 * */
/*
/*
6 6
0 4
1 3
2 3
3 0
4 1
5 0*/