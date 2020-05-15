#include<bits/stdc++.h>
using namespace std;
int main(){
    int N = 7; int E = 8;
    //--------------------Adjacency Matrix--------------------------------// 
    vector<vector<int>>G(N,vector<int>(N,0));
    vector<pair<int,int>>Edges;
    vector<int>W;
    printf("Enter the edges and the weight\n");
    for(int i = 0;i<E;i++){
        int E1 , E2 , WE;
        scanf("%d %d %d",&E1,&E2,&WE);
        Edges.push_back(make_pair(E1,E2));
        W.push_back(WE);
    }
    vector<pair<int,int>>::iterator p = Edges.begin();
    int index = 0;
    for(;p!=Edges.end();p++){
        G[p->first][p->second] = W[index];
        G[p->second][p->first] = W[index++];
    } 
    vector<vector<int>>::iterator Gi = G.begin();
    for(;Gi != G.end();Gi++){
        vector<int>T = *Gi;
        for(int i=0;i<T.size();i++)
            printf("%d ",T[i]);
        printf("\n");
    }
    //----------------------------------------------------------------------//
    //---------------------------Adjacency List-----------------------------//
    vector<vector<pair<int,int>>>LIST(N,vector<pair<int,int>>());
    p = Edges.begin();
    index = 0;
    for(;p!=Edges.end();p++){
        LIST[p->first].push_back(make_pair(p->second,W[index]));
        LIST[p->second].push_back(make_pair(p->first,W[index++]));
    }
    vector<vector<pair<int,int>>>::iterator Li = LIST.begin();
    int V  = 0;
    for(;Li != LIST.end();Li++){
        printf("%d-->",V);
        vector<pair<int,int>>T = *Li;
        for(int j=0;j<T.size();j++)
            printf("%d:%d ",T[j].first,T[j].second);
        printf("\n");
        V++;
    }
    //----------------------------------------------------------------------//
    //------------------------EdgeList--------------------------------------//
    vector<pair<int,pair<int,int>>>EL(E*2,make_pair(0,make_pair(0,0)));
    p = Edges.begin();
    index = 0; int EN = 0;
    for(;p!=Edges.end();p++){
        //EL[p->first].first = W[index]; EL[p->first].second.first = p->first; EL[p->first].second.second = p->second;
        //EL[p->second].first = W[index++]; EL[p->second].second.first = p->second; EL[p->second].second.second = p->first; 
        int E1 = p->first; int E2 = p->second;
        EL[EN].first = W[index]; EL[EN].second.first = E1; EL[EN].second.second = E2;
        EN++;
        EL[EN].first = W[index]; EL[EN].second.first = E2; EL[EN].second.second = E1;
        EN++;
        index++;
    }

    vector<pair<int,pair<int,int>>>::iterator Ei = EL.begin();
    EN = 0;
    for(;Ei != EL.end();Ei++){
        printf("%d: ",EN++);
        pair<int,pair<int,int>>T = *Ei;
        printf("W--> %d: E--> (%d, %d)\n",T.first,T.second.first,T.second.second);
    }
    return 0;
}