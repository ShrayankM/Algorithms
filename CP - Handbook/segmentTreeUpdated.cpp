#include<bits/stdc++.h>
using namespace std;

struct SegmentTree{
    int st[25]; int size; int N;
    SegmentTree(int N){
        this->N = N;
        //st = new int[4 * N + 1];
        size = 4 * N;
    }

    int left(int p){
        return p << 1;
    }

    int right(int p){
        return (p << 1) + 1;
    }

    void build(int A[], int p, int L, int R){
        if(L == R){
            st[p] = L;
            return;
        }
        build(A, left(p), L, (L + R)/2);
        build(A, right(p), (L + R)/2 + 1, R);
        int p1 = st[left(p)]; int p2 = st[right(p)];

        st[p] = (A[p1] >= A[p2]) ? p1 : p2;
    }

    int RMQ(int A[], int p, int L, int R, int i, int j){
        if(i > R || j < L)
            return -1;
        if(L >= i && R <= j)
            return st[p];
        
        int p1 = RMQ(A, left(p), L, (L + R)/2, i, j);
        int p2 = RMQ(A, right(p), (L + R)/2 + 1, R, i, j);
        if(p1 == -1)
            return p2;
        if(p2 == -1) 
            return p1;
        
        return (A[p1] >= A[p2]) ? p1 : p2;
    }

    int RMQ(int A[], int i, int j){
        return RMQ(A, 1, 0, N - 1, i, j);
    }

    int find(int p, int L, int R, int index){
        if(L == R && L == index)
            return p;
        if(index >= L && index <= (L + R)/2)
            return find(left(p), L, (L + R)/2, index);
        return find(right(p), (L + R)/2 + 1, R, index);
    }

    void update(int A[], int index, int key){
        int L = 0, R = N - 1;
        int p = find(1, 0, N - 1, index);
        while(p > 1 && A[st[p]] >= A[st[p/2]]){
            st[p/2] = st[p];
            p = p/2;
        }
    }
};

int main(){

    int A[] = {12, 34, 56, 18, 17, 5, 78, 55, 19, 78, 7, 23};
    int N = sizeof(A)/sizeof(int);

    struct SegmentTree t(N);
    t.build(A, 1, 0, N - 1);

    cout << A[t.RMQ(A, 1, 4)] << "\n";
    cout << A[t.RMQ(A, 0, 11)] << "\n";

    //A[1] = 80; 
    A[4] = 180;
    //t.update(A, 1, 80);
    t.update(A, 4, 180);
    cout << A[t.RMQ(A, 0, 11)] << "\n";
    return 0;
}


/**
 * TODO Update query has been modified to perform in O(logn) time Complexity
 * ? find(int p, int L, int R, int index) is used to find the index position in 
 * ? segment tree recursively TC O(logn)
 * * Once p has been found go back upwards on the tree from parent to parent
 * * updating the values of segment tree TC O(logn)
 * */