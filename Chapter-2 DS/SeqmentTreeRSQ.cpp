#include<bits/stdc++.h>
using namespace std;
struct SegmentTree{
    vector<int>A,st; int n;
    int left(int p){
        return (p << 1);
    }
    int right(int p){
        return (p << 1) + 1;
    }
    void build(int p,int L,int R){
        if(L == R)
            st[p] += A[L];
        else{
            build(left(p),L,(L + R)/2);
            build(right(p),(L + R)/2 + 1,R);
            int p1 = st[left(p)]; int p2 = st[right(p)];
            st[p] += p1 + p2;
        }
    }
    SegmentTree(vector<int>_A){
        n = (int)_A.size();
        A = _A; st.assign(4*n,0);
        build(1,0,n-1);
    }
    int rsq(int p,int L,int R,int i,int j){
        if(i > R || j < L)
            return -1;
        if(L >= i && R <= j)
            return st[p];

        int p1 = rsq(left(p),L,(L + R)/2,i,j);
        int p2 = rsq(right(p),(L + R)/2 + 1,R,i,j);

        if(p1 == -1)
            return p2;
        else if(p2 == -1)
            return p1;
        else
            return (p1 + p2);
    }
    int rsq(int i,int j){
        return rsq(1,0,n-1,i,j);
    }

    void displaySt(){
        for(int i=0;i<st.size();i++)
            printf("%d ",st[i]);
        printf("\n");
    }
};
int main(){
    int A[] = { 18, 17, 13, 19, 15, 11, 20 };
    vector<int>_A(A,A+7);
    SegmentTree st(_A);
    //st.displaySt();
    printf("RSQ(1, 3) = %d\n", st.rsq(1, 3));
    return 0;
}