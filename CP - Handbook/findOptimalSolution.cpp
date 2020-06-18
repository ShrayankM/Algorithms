#include<iostream>
using namespace std;

const int K = 336, Nmax = 1000;

bool valid(int a){
    if(a < K)
        return false;
    return true;
}
int main(){
    int x = 0;
    for(int i = Nmax/2; i >= 1; i = i/2){
        while(!valid(x + i))
            x = x + i;
    }
    cout << x + 1 << "\n";
    return 0;
}


//Question: BinarySearch the max value of x such that the function valid returns false; 