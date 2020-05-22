#include<cstdio>
using namespace std;
const int NMAX = 7;
int S[NMAX];
//Brute Force TC = O(N^2)
int maxSum(int A[]){
    int ans = 0;
    for(int i = 0; i < NMAX; i++){
        int sum = 0;
        for(int j = i; j < NMAX; j++){
            sum += A[j];
            if(sum > ans)
                ans = sum;
        }
    }
    return ans;
}

//Greedy Approach O(N)
int maxSumG(int A[]){
    int ans = 0, sum = 0;
    for(int i = 0; i < NMAX; i++){
        sum += A[i];
        if(sum > ans)
            ans = sum;
        if(sum < 0)
            sum = 0;
    }
    return ans;
}

//PartialSums Brute Force O(N^2)
int maxSumP(int A[]){
    S[1] = A[1];
    for(int i = 2; i <= NMAX; i++)
        S[i] = S[i - 1] + A[i];
    int ans = 0;
    for(int i = 1; i <= NMAX; i++){
        int sum = 0;
        for(int j = i; j <= NMAX; j++){
            sum = S[j] - S[i - 1];
            if(sum > ans)
                ans = sum;
        }
    }
    return ans;
}

//PartialSums Optimal O(N)
int maxSumPO(int A[]){
    S[1] = A[1];
    for(int i = 2; i <= NMAX; i++)
        S[i] = S[i - 1] + A[i];
    int ans = S[1], minS = 0;
    for(int i = 1;i <= NMAX; i++){
        if(S[i] - minS > ans)
            ans = S[i] - minS;
        if(S[i] < minS)
            minS = S[i];
    }
    return ans;
}
int main(){
    int A[] = {5, -6, 3, 4, -2, 3, -3};
    int A2[] = {-99, 5, -6, 3, 4, -2, 3, -3};
    printf("Brute Force TC = O(N^2) %d\n",maxSum(A));
    printf("Greedy Approach TC = O(N) %d\n",maxSumG(A));
    printf("PartialSums Brute Force TC = O(N^2) %d\n",maxSumP(A2));
    printf("PartialSums Optimal TC = O(N) %d\n",maxSumPO(A2));
    return 0;
}