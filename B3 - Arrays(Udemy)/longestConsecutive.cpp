#include<bits/stdc++.h>
using namespace std;
const int NMAX = 10;
bool fr[100];


//Optimal TC = O(N^2)
int longestSequence(int A[]){
    int ans = 0;
    for(int i = 0; i < NMAX; i++){
        int MIN = A[i], MAX = A[i];
        for(int i = 0; i < 100; i++)
            fr[i] = false;
        for(int j = i; j < NMAX; j++){
            if(fr[A[j]] == true)
                break;
            fr[A[j]] = true;
            MIN = min(MIN,A[j]); MAX = max(MAX,A[j]);
            if(j - i == MAX - MIN)
                ans = max(ans,j - i + 1);
        }
    }
    return ans;
}
int main(){
    int A[] = {3, 7, 1, 4, 2, 5, 3, 8, 10, 9};
    printf("%d \n",longestSequence(A));
    return 0;
}