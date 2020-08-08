#include<cstdio>
#include<algorithm>
using namespace std;

const int Nmax = 10001;
int A[Nmax]; int N, K;

int sumOf(){
    int sum = 0;
    for(int i = 1; i <= N; i++)
        sum += A[i];
    return sum;
}

bool isValid(int X){
    int count = 0;
    for(int i = 1; i <= N; i++)
        count += min(X, A[i]);
    return count >= X * K;
}
int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    
    int L = 0, R = sumOf()/K; int M;
    while(L <= R){
        M = (L + R)/2;
        if(isValid(M))
            L = M + 1;
        else
            R = M - 1;
    }
    printf("Groups Possible: %d\n", M);
    return 0;
}
/*
Yout have N different types of animals, for each type knowing how many animals you 
have of that type. You have to sell these animals only in groups of K distinct animals
Find Max No. of groups you can sell.

Example: N = 7, K = 5  A = [1, 2, 3, 4, 5, 6, 7] Answer: 5

*/

//Input File
/*
7 5
1 2 3 4 5 6 7
*/