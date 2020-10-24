#include<bits/stdc++.h>
using namespace std;

int findSubString(string str) {
    int maxLen = 0;

    for (int i = 0; i < str.size(); i++) {
        for (int j = i + 1; j < str.size(); j = j + 2) {

            int len = j - i + 1;

            if (maxLen >= len) continue;
            int lSum = 0, rSum = 0;
            for (int k = i; k < len/2; k++) {
                lSum += str[k] - '0';
                rSum += str[k + len/2] - '0';
            }

            if (lSum == rSum) maxLen = len;
        }
    }
    return maxLen;
}


int maxSubString(string str) {
    int maxLen = 0;
    int n = str.size();

    int sum[n][n];

    for (int i = 0; i < n; i++) {
        sum[i][i] = str[i] - '0';
    }

    for (int x = 2; x <= n; x++) {

        for (int i = 0; i < n - x + 1; i++) {
            int j = i + x - 1;
            int k = x/2;

            sum[i][j] = sum[i][j - k] + sum[j - k + 1][j];

            if (x % 2 == 0 && sum[i][j - k] == sum[j - k + 1][j] && x > maxLen) maxLen = x;
        }
    }
    return maxLen;
}

int main(){

    string str = "9430723";
    cout << findSubString(str) << "\n";
    cout << maxSubString(str) << "\n";
    return 0;
}