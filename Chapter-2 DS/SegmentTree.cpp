#include<bits/stdc++.h>
using namespace std;
struct SegmentTree{
    vector<int>st; vector<int>A;
    int N;
    int left(int p){
        return (p << 1);
    }

    int right(int p){
        return (p << 1) + 1;
    }

    void build(int p,int L,int R){
        if(L == R)
            st[p] = L;
        else{
            build(left(p),L,(L+R)/2);
            build(right(p),(L+R)/2 + 1,R);
            int p1 = st[left(p)]; int p2 = st[right(p)];
            if(A[p1] <= A[p2])
                st[p] = p1;
            else 
                st[p] = p2;
        }
    }
    SegmentTree(const vector<int>&_A){
        A = _A;
        N = (int)_A.size();
        st.assign(4*N,0);
        build(1,0,N-1);
    }
    int rmq(int p,int L,int R,int i,int j){
        if(i > R || j < L)
            return -1;
        if(L >= i && R <= j)
            return st[p];

        int p1 = rmq(left(p),L,(L+R)/2,i,j);
        int p2 = rmq(right(p),(L+R)/2 + 1,R,i,j);

        if(p1 == -1)
            return p2;
        if(p2 == -1)
            return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }
    void displayST(){
        for(int i=1;i<st.size();i++)
            printf("%d ",st[i]);
        printf("\n");
    }
    int rmq(int i,int j){
        return rmq(1,0,N-1,i,j);
    }
};
int main(){
    int arr[] = { 18, 17, 13, 19, 15, 11, 20 };
    vector<int>A(arr,arr+7);
    struct SegmentTree S(A);
    //S.displayST();
    printf("RMQ(1, 3) %d\n",S.rmq(1, 3));
    printf("RMQ(4, 6) %d\n",S.rmq(4, 6));
    return 0;
}