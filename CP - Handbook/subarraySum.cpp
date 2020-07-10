#include<bits/stdc++.h>
using namespace std;

/** 
 * ! Caution O(N) TC function not full proof 
 * */

const int Nmax = 101;
int A[Nmax];

bool checkSum(int n, int sum){
    for(int i = 1; i <= n; i++){
        int c = 0;
        for(int j = i; j <= n; j++){
            c += A[j];
            if(c == sum)
                return true;
        }
    }
    return false;
}

bool checkSum_dp(int n, int sum){
    int L = 1, R = L;
    int c = A[L];
    while(R < n){
        while(c <= sum && R <= n){
            R++;
            c = c + A[R];
        }
        c = c - A[R]; R--;
        if(c == sum)
            return true;
        c = c - A[L]; L++;
    }
    return false;
}

int main(){
    freopen("input.txt", "r", stdin);
    int n, sum;
    cin >> n >> sum;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    
    if(checkSum(n, sum))
        cout << "Subarray with " << sum << " exists" << "\n";
    else
        cout << "No Subarray with " << sum << " exists" << "\n";

    if(checkSum_dp(n, sum))
        cout << "Subarray with " << sum << " exists" << "\n";
    else
        cout << "No Subarray with " << sum << " exists" << "\n";
    return 0;
}