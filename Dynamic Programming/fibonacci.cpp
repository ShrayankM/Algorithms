#include<bits/stdc++.h>
using namespace std;

const int Nmax = 1000;
bool fibCheck[Nmax];
long long fibStore[Nmax];

long long fib(int n) {
    if (n == 1 || n == 2) return 1;

    if (fibCheck[n]) return fibStore[n];

    fibCheck[n] = true;
    fibStore[n] = fib(n - 1) + fib(n - 2);
    return fibStore[n];
}


long long fibIterative(int n) {
    if (n == 1 || n == 2) return 1;

    long long a = 1, b = 1, c = 0;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){

    long long ans = fib(80);
    cout << ans << "\n";

    ans = fibIterative(80);
    cout << ans << "\n";
    return 0;
}