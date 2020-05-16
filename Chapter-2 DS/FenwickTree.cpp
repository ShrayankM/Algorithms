#include<bits/stdc++.h>
using namespace std;

#define LSOne(i) (i & (-i))
struct Fenwick{
    vector<int>ft;
    Fenwick(int N){
        ft.assign(N+1,0);
    }

    void adjust(int k,int v){
        for(;k<(int)ft.size();k=k+LSOne(k))
            ft[k] += v;
    }

    int rsq(int b){
        int sum = 0;
        for(;b>0;b=b-LSOne(b))
            sum += ft[b];
        return sum;
    }

    int rsq(int a,int b){
        return rsq(b) - (a == 1 ? 0:rsq(a - 1));
    }
};
int main(){
    Fenwick ft(10);
    ft.adjust(2,1);
    ft.adjust(4,1);
    ft.adjust(5,2);
    ft.adjust(6,3);
    ft.adjust(7,2);
    ft.adjust(8,1);
    ft.adjust(9,1);
    printf("%d\n", ft.rsq(3, 6));

    ft.adjust(5, 2);
    printf("%d\n", ft.rsq(1, 10)); 
    return 0;
}