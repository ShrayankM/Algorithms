#include<bits/stdc++.h>
using namespace std;

// ? Cost to get from station i to j 
// * (station nos. from 0 to N - 1)

const int Nmax = 100;

int memo[Nmax][Nmax] = {0};

int cost[][4] = {
    {0, 10, 75, 94},
    {-1, 0, 35, 50},
    {-1, -1, 0, 80},
    {-1, -1, -1, 0},
};

// Recursive Memoization
long long minTravelCost(int s, int d) {

    if (s == d || s == d - 1) return cost[s][d];

    if (memo[s][d] != 0) return memo[s][d];
    long long minCost = cost[s][d];

    for (int i = s + 1; i < d; i++) {
        long long temp = minTravelCost(s, i) + minTravelCost(i, d);
        minCost = min(minCost, temp);
    }
    memo[s][d] = minCost;
    return minCost;
}

//Dynamic programming
int minCost[Nmax] = {0};

long long calculateMin(int n) {
    minCost[0] = 0;
    minCost[1] = cost[0][1];

    for (int i = 2; i < n; i++) {
        minCost[i] = cost[0][i];

        for (int j = 1; j < i; j++) {
            minCost[i] = min(minCost[i], minCost[j] + cost[j][i]);
        }
    }
    return minCost[n - 1];
}

int main(){

    int source = 0, destination = 3;
    // long long ans = minTravelCost(source, destination);
    long long ans = calculateMin(4);
    cout << ans << "\n";
    return 0;
}

