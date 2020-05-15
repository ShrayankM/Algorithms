#include<bits/stdc++.h>
using namespace std;
struct UnionFind{
    vector<int>P, R,SetSize;
    int numSets;
    UnionFind(int N){
        numSets = N;
        R.assign(N,0);
        SetSize.assign(N,1);
        for(int i=0;i<N;i++)
            P.push_back(i);
    }
    int findSet(int i){
        if(P[i] == i)
            return i;
        else
            return findSet(P[i]);
    }

    bool isSameSet(int i,int j){
        return findSet(i) == findSet(j);
    }

    void UnionSet(int i,int j){
        if(!isSameSet(i,j)){
            numSets--;
            int x = findSet(i); int y = findSet(j);
            if(R[x] > R[y]){
                P[y] = x;
                SetSize[x] += SetSize[y];
            }
           else{
               P[x] = y;
               SetSize[y] += SetSize[x];
               if(R[x] == R[y])
                    R[y]++;
           }
        }
    }
    int numDisjointSets(){
        return numSets;
    }

    int sizeOfSet(int i){
        return SetSize[findSet(i)];
    }
};
int main(){
    struct UnionFind UF(5);
    UF.UnionSet(0,1);
    UF.UnionSet(2,3);
    UF.UnionSet(4,3);

    printf("The Number of Sets are:%d\n",UF.numDisjointSets());
    printf("The Number of Elements with 3 are:%d\n",UF.sizeOfSet(3));

    UF.UnionSet(0,3);
    printf("The Number of Sets are:%d\n",UF.numDisjointSets());
    printf("The Number of Elements with 3 are:%d\n",UF.sizeOfSet(3));
    return 0;
}