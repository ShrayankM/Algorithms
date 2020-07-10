#include<bits/stdc++.h>
using namespace std;

const int Nmax = 101;
int A[Nmax];
int N[Nmax];

void findNearest(int n){
    stack<pair<int, int>>S;
    S.push(make_pair(A[1], 1));
    for(int i = 2; i <= n; i++){
        if(S.top().first <= A[i]){
            S.push(make_pair(A[i], i));
            continue;
        }
        else if(S.top().first > A[i]){
            while(S.top().first > A[i] || S.empty()){
                int a = S.top().first; int index = S.top().second; 
                S.pop();
                N[index] = A[i];
            }
            S.push(make_pair(A[i], i));
        }
    }

    for(int i = 1; i <= n; i++)
        cout << N[i] << " ";
    cout << "\n";
}

int main(){

    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    
    findNearest(n);
    return 0;
}