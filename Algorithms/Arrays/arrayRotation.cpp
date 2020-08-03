#include<bits/stdc++.h>
using namespace std;
int main(){

    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 11;

    int n = sizeof(A)/sizeof(int);
    /**
     * TODO LEFT rotation
     * */
    int mod = k%n;
    for(int i = 0; i < n; i++)
        cout << A[(mod + i)%n] << " ";
    cout << "\n";

    /**
     * TODO RIGHT rotation
     * */
    int* R = new int[n + 1];
    for(int i = 0; i < n; i++)
        R[(i + k)%n] = A[i];
    
    for(int i = 0; i < n; i++)
        cout << R[i] << " ";
    cout << "\n";
    return 0;
}