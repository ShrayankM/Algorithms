#include<bits/stdc++.h>
using namespace std;

long long power(int a, int n) {
    if (n == 1) return a;

    if (n % 2 == 0) return power(a * a, n/2);
    return power(a * a, (n - 1)/2) * a;
}

int main(){


    int a = 2; int n = 11;
    long long ans = power(a, n);

    cout << ans << "\n";
    return 0;
}