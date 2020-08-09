#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b, int* x, int* y){
    if(b == 0){
        *x = 1; *y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b) * y1;
    return g;
}

int main(){

    int a, b;
    printf("Enter A and B: ");
    scanf("%d %d", &a, &b);

    int x, y;
    printf("ax + by = gcd(a, b): x = %d, y = %d, gcd(a, b) = %d\n",
             x, y, gcd(a, b, &x, &y));
    return 0;
}