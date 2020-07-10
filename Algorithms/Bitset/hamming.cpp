#include<bits/stdc++.h>
using namespace std;

int hamming(vector<string>S){
    int d = INT32_MAX * -1;
    for(int i = 0; i < (int)S.size(); i++){
        for(int j = i + 1; j < (int)S.size(); j++){
            string a = S[i]; string b = S[j];
            int diff = 0;
            for(int k = 0; k < (int)a.size(); k++){
                if(a[k] != b[k])
                    diff++;
            }
            d = max(d, diff);
        }
    }
    return d;
}

int hammingBit(vector<string>S){
    int d = INT32_MAX * -1;
    for(int i = 0; i < (int)S.size(); i++){
        for(int j = i + 1; j < (int)S.size(); j++){
            int a = stoi(S[i], 0, 2); int b = stoi(S[j], 0, 2);
            d = max(d, __builtin_popcount(a ^ b));
        }
    }
    return d;
}

int main(){

    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<string>S(n);
    for(int i = 0; i < n; i++)
        cin >> S[i];

    cout << hamming(S) << "\n";

    cout << hammingBit(S) << "\n";
    return 0;
}