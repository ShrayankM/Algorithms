#include<bits/stdc++.h>
using namespace std;

const int Nmax = 101;
int A[Nmax];

void _2sum(int n, int sum){
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(A[i] + A[j] == sum){
                cout << A[i] << " + " << A[j] << " = " << sum << "\n";
                return;
            }
        }
    }
    cout << "Sum does not exist " << "\n";
}

void _2sum_dp(int n, int sum){
    sort(A, A + n + 1);
    int i = 1, j = n;
    while(i < j){
        if(sum == (A[i] + A[j])){
            cout << A[i] << " + " << A[j] << " = " << sum << "\n";
            return;
        }
        else if(sum > (A[i] + A[j])){
            i++;
        }
        else{
            j--;
        }
    }
    cout << "Sum does not exist " << "\n";
}

int main(){

    freopen("input.txt", "r", stdin);
    int n, sum;
    cin >> n >> sum;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    
    _2sum(n, sum);

    _2sum_dp(n, sum);
    return 0;
}