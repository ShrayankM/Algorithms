#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

void binarySearch(int A[], int N, int X){
    int K = 0;
    for(int i = N/2; i >= 1; i = i/2){
        while(K + i < N && A[K + i] <= X)
            K = K + i;
    }
    if(A[K] == X)
        cout << "Found\n";
    else
        cout << "Not Found\n";
}

void display(int A[], int N){
    for(int i = 0; i < N; i++){
        cout << A[i] << "(" << i << ")" << " ";
    }
    cout << "\n";
}
int main(){
    int A[] = {45, 4, 67, 12, 78, 3, 2, 16, 21, 79, 78, 45, 64, 55};
    int N = sizeof(A)/sizeof(int);
    int X;
    cin >> X;
    sort(A, A + N);
    display(A, N);
    binarySearch(A, N, X);
    return 0;
}