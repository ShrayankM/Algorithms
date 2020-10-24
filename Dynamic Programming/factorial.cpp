#include<bits/stdc++.h>
using namespace std;

const int Nmax = 1000;
bool factCheck[Nmax];
long long factStore[Nmax];

long long fact(long n) {
    if (n == 0 || n == 1) return 1;

    if (factCheck[n]) return factStore[n];

    factCheck[n] = true;
    factStore[n] = n * fact(n - 1);
    return factStore[n];
}

int main(){
    cout << fact(10) << "\n";
    return 0;
}