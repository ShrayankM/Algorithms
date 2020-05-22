#include<cstdio>
using namespace std;
const int NMAX = 100;
int fr[NMAX];

void findNumber(int N){
    int cur_rem = 0;
    for(int i = 1; i <= N; i++){
        cur_rem = (cur_rem * 10 + 1) % N;
        if(cur_rem == 0){
            for(int j = 1; j <= i; j++)
                printf("1");
            return;
        }
        if(fr[cur_rem] != 0){
            for(int j = 1; j <= i - fr[cur_rem]; j++)
                printf("1");
            for(int j = 1; j <= fr[cur_rem]; j++)
                printf("0");
            return;
        }
        fr[cur_rem] = i;     
    }
}
int main(){
    int N = 15;
    findNumber(N);
    return 0;
}