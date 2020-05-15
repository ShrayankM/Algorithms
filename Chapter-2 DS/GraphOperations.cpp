#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>M = {{0,1,0,1,1},{0,0,1,0,1},{0,0,0,0,0},
                            {0,0,1,0,1},{0,1,0,0,0}};
    int N = 5;
    int E = 0, V = 0;
    //------------------------------Count Edges--------------------------//
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(M[i][j] == 1){
                E++;
            }
        }
    }
    printf("Edges:%d\n\n",E);
    //-----------------------------------------------------------------//
    //----------------------InDegree OutDegree-------------------------//
    int OUT = 0, IN = 0;
    for(int i=0;i<N;i++){
        OUT = 0; IN = 0;
        for(int j=0;j<N;j++){
            if(M[i][j] == 1)
                OUT++;
            if(M[j][i] == 1)
                IN++;
        }
        printf("OUT Degree of vertex %d is %d\n",i,OUT);
        printf("IN Degree of vertex %d is %d\n\n",i,IN);
    }
    //-----------------------------------------------------------------//
    //-------------------------Transpose-------------------------------//
    printf("Reversing the Directed Edges");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d ",M[j][i]);
        printf("\n");
    }
    //-----------------------------------------------------------------//
    //-----------------Complete Graph Check----------------------------//
    int Vertices = N; int Edges = E;
    if(E == (N * (N - 1)/2))
        printf("Complete Graph\n");
    else
        printf("Not Complete Graph\n");
    //-----------------------------------------------------------------//

    return 0;
}