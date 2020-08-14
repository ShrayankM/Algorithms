#include<bits/stdc++.h>
using namespace std;

int findmax(int a[], int n){
    int m = 0;
    for(int i = 0; i < n; i++){
        m = max(m, a[i]);
    }
    return m;
}

void binsort(int a[], int n){
    vector<int> b[findmax(a, n) + 1];
    for(int i = 0; i < n; i++){
        b[a[i]].push_back(a[i]);
    }

    int k = 0; 
    for(int i = 0; i < findmax(a, n) + 1; i++){
        vector<int>temp = b[i];
        for(auto c: temp)
            printf("%d ", c);
    }
    printf("\n");
}
int main(){

    int a[] = {1, 5, 6, 2, 6, 7, 10, 9, 1, 3, 4, 5, 6, 7};
    int n = sizeof(a)/sizeof(int);

    binsort(a, n);
    return 0;
}