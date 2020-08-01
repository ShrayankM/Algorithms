#include<bits/stdc++.h>
using namespace std;

const int n = 1000;
int a = 4, b = 7;
vector<int>V;

void generate(long long v, int n){
    if(v > n)
        return;
    if(v > 0)
        V.push_back(v);
    generate(10 * v + a, n);
    generate(10 * v + b, n);
}

int main(){
    generate(0, n);
    for(auto c: V)
        cout << c << " ";
    cout << "\n";
    return 0;
}

/**
 * TODO Generate all possible numbers using digits a and b upto n
 * */