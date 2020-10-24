#include<bits/stdc++.h>
using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6};

int findSum(int n) {
    if (n == 0) return arr[0];

    int t = findSum(n - 1);
    arr[n] = arr[n] + t;
    return arr[n]; 
}

int main(){

    int n = sizeof(arr)/sizeof(int);
    findSum(n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}