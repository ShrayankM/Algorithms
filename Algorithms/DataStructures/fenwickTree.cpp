#include<bits/stdc++.h>
using namespace std;

struct FenwickTree{
    int* ft; int N;
    FenwickTree(int n){
        N = n;
        ft = new int[N + 1];
        for(int i = 1; i <= N; i++)
            ft[i] = 0;
    }
    int LSOne(int b){
        return (b & -b);
    }
    int rsq(int b){
        int sum = 0;
        for(;b > 0; b = b - LSOne(b))
            sum += ft[b];
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b) - (a == 1 ? 0:rsq(a - 1));
    }
    void adjust(int k, int v){
        for(; k <= N; k = k + LSOne(k))
            ft[k] += v;
    }
    void displayTree(){
        for(int i = 1; i <= N; i++)
            printf("%d ", ft[i]);
        printf("\n");
    }
};

int main(){

    int A[] = {1, 3, 4, 8, 6, 1, 4, 2};
    int N = sizeof(A)/sizeof(int);
    FenwickTree T(N);
    for(int i = 0; i < N; i++)
        T.adjust(i + 1, A[i]);
    T.displayTree();
    printf("%d\n", T.rsq(1, 7));
    printf("%d\n", T.rsq(3, 6));
    return 0;
}