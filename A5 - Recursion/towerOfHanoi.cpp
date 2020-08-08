#include<bits/stdc++.h>
using namespace std;
void TOH(int N,int A,int B,int C){
    if(N > 0){
        TOH(N-1,A,C,B);
        printf("(%d, %d)\n",A,C);
        TOH(N-1,B,A,C);
    }
}
int main(){
    TOH(6,1,2,3);
    cout<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0;
}