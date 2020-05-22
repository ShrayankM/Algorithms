#include<bits/stdc++.h>
using namespace std;
const int NMAX = 100005; int fr[NMAX];
//Brute Force O(N^2)
int longestSequence(int A[], int N, int K){
    int ans = 0;
    for(int i = 0; i < N; i++){
        int count = 0;
        for(int j = 0; j < NMAX; j++)
            fr[j] = 0;
        for(int j = i; j < N; j++){
            if(++fr[A[j]] == 1)
                count++;
            if(count <= K)
                ans = max(ans,j - i + 1);
        }
    }
    return ans;
}

//Optimal SlidingWindow Technique  TC = O(N)
int longestSequenceO(int A[], int N,int K){
    for(int k = 0; k < NMAX; k++)
            fr[k] = 0;
    int ans = 0, count = 0, j;
    for(j = 0; j < N; j++){
        if(++fr[A[j]] == 1)
            count++;
        if(count > K)
            break;
    }
    if(count <= K)
        return N;
    if(--fr[A[j--]] == 0)
        count--;
    for(int i = 1; i < N; i++){
        if(--fr[A[i - 1]] == 0)
            count--;
        while(j < N - 1){
            if(++fr[A[++j]] == 1)
                count++;
            if(count > K)
                break;
        }
        if(count <= K)
            return max(ans, N - i + 1);
        if(--fr[A[j--]] == 0)
            count--;
        ans = max(ans, j - i + 1);
    }
    return ans;
}
int main(){
    int A[] = {1, 5, 2, 1, 7, 2, 1, 5, 5, 7}; int K = 3; int N = 10;
    printf("Brute Force TC = O(N^2) %d \n",longestSequence(A,N,K));
    printf("Optimal SlidingWindow TC = O(N) %d \n",longestSequenceO(A,N,K));
    return 0;
}