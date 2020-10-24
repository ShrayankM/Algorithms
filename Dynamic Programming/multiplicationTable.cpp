#include<bits/stdc++.h>
using namespace std;

void table(int n, int i, int current) {
    if (i == 11) return;
    cout << n << " x " << i << " = " << current << "\n";
    table(n, i + 1, current + n); 
}

int main(){

    int n = 3;
    table(n, 1, n);
    return 0;
}