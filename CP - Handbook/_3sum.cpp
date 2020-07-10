#include<bits/stdc++.h>
using namespace std;

const int Nmax = 101;
int A[Nmax];

void _3sum(int n, int sum){
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int k = j + 1; k <= n; k++){
                if((A[i] + A[j] + A[k]) == sum){
                    cout << A[i] << " + " << A[j] << " + " << A[k] << " = " << sum << "\n";
                    return;
                }
            }
        }
    }
    cout << "Sum does not exist " << "\n";
}

void _3sum_dp(int n, int sum){
    for(int k = 1; k <= n; k++){
        int i = k + 1; int j = n;
        int c = A[k];
        while(i < j){
            if(c + A[i] + A[j] == sum){
                cout << A[i] << " + " << A[j] << " + " << A[k] << " = " << sum << "\n";
                return;
            }
            else if(sum > (c + A[i] + A[j]))
                i++;
            else
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
    
    _3sum(n, sum);
    _3sum_dp(n, sum);
    return 0;
}