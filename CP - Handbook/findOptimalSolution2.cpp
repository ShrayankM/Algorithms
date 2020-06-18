#include<cstdio>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
int K = 8, N = 3;
int P[] = {2, 3, 7};

bool valid(int x){
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += (int)floor(x/P[i]);
    if(sum >= K)
        return true;
    return false;
}

int main(){
    int x = 0, ans = *max_element(P, P + N) * K;
    for(int i = *max_element(P, P + N) * K; i >= 1; i = i/2){
            while(!valid(x + i))
                x = x + i;
            if(valid(x + i))
            	ans = min(ans, (x + i));
    }
    cout << ans << "\n";
    return 0;
}

//Question: Find the minimum time required to process (K) jobs on (N) machines
//          where time to process one job for every machine is given;
