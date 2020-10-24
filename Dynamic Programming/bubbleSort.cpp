#include<bits/stdc++.h>
using namespace std;


void swap(int *arr, int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

void bubblesort(int *arr, int n) {
    if (n == 1) return;
    for (int j = 0; j < n - 1; j++)
        if (arr[j] > arr[j + 1])
            swap(arr, j, j + 1);
    bubblesort(arr, n - 1);
}

int main(){

    int arr[] = {12, 45, 6, 78, 34, 21, 36};
    int n = sizeof(arr)/sizeof(int);

    bubblesort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}