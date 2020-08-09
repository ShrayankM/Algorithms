#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int *a;
    int* st; int N;
    SegmentTree(int n, int A[]){
        N = 4 * n;
        a = A;
        st = new int[N];
        for(int i = 0; i < N; i++)
            st[i] = -1;
    }
    int left(int p){
        return (p << 1);
    }
    int right(int p){
        return (p << 1) + 1;
    }
    void buildRMQ(int p, int L, int R){
        if(L == R)
            st[p] = L;
        else{
            buildRMQ(left(p), L, (L + R)/2);
            buildRMQ(right(p), (L + R)/2 + 1, R);
            int p1 = st[left(p)]; int p2 = st[right(p)];
            st[p] = (a[p1] <= a[p2] ? p1 : p2);
        }
    }
    int rmq(int i, int j){
        return rmq(1, 0, (N/4 - 1), i, j);
    }
    int rmq(int p, int L, int R, int i, int j){
        if(i > R || j < L)
            return -1;
        if(L >= i && R <= j)
            return st[p];
        int p1 = rmq(left(p), L, (L + R)/2, i, j);
        int p2 = rmq(right(p), (L + R)/2 + 1, R, i, j);
        if(p1 == -1)
            return p2;
        if(p2 == -1)
            return p1;
        return (a[p1] <= a[p2] ? p1:p2);
    }
    void update(int index, int v){
        int L = 0; int R = (N/4 - 1);
        int p = 1;
        while(true){
            if(L == R && L == index)
                break;
            if(index >= L && index <= (L + R)/2){
                R = (L + R)/2;
                p = left(p);
            }
            else if(index >= (L + R)/2 + 1 && index <= R){
                L = (L + R)/2 + 1;
                p = right(p);
            }
        }
        while(p > 0){
           int LC, RC;
           if(p%2 == 0){
                LC = st[p];
                RC = st[p + 1];
           }
           else{
               LC = st[p - 1];
               RC = st[p];
           }
           st[p/2] = (a[LC] <= a[RC] ? LC:RC);
           p = p/2;
        }
    }
    void displayTree(){
        for(int i = 1; i < N; i++)
            printf("%d ", st[i]);
        printf("\n");
    }
};
int main(){

    int A[] = {18, 17, 13, 19, 15, 11, 20};
    int N = sizeof(A)/sizeof(int);
    SegmentTree T(N, A);
    T.buildRMQ(1, 0, N - 1);
    T.displayTree();
    printf("%d\n", T.rmq(1, 3));
    printf("%d\n", T.rmq(4, 6));

    A[5] = 99;
    T.update(5, 99);
    T.displayTree();
    //SeqmentTree TS(N, A);
    //TS.buildRSQ(1, 0, N - 1);

    printf("%d\n", T.rmq(1, 3));
    printf("%d\n", T.rmq(4, 6));
    return 0;
}


/** 
 * TODO Time Complexities of all functions
 * ? TC buildRMQ(p, L, R) O(N) 
 * * TC rmq(i, j) O(logN) 
 * ? TC update(index, value) O(logN) 
 * */