#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
const int Nmax = 1000;
int Qcount = 0, Count = 0, N;
int R[Nmax], C[Nmax], D1[Nmax], D2[Nmax];

int TSolutionsB(){
    for(int i = 0; i < N; i++){
        R[i] = 1;
        for(int j = 0; j < N; j++){
            C[j] = D1[j + i] = D2[j - i + N - 1] = 1;
            for(int a = i + 1; a < N; a++){
                for(int b = j + 1; b < N; b++){
                    if(R[a] || C[b] || D1[b + a] || D2[b - a + N - 1])
                        continue;
                    else
                        Count++;
                }
            }
            C[j] = D1[j + i] = D2[j - i + N - 1] = 0;
        }
        R[i] = 0;
    }
    return Count * 2;
}

int TSolutions(int N){
    if(N <= 2)
        return 0;
    return TSolutions(N - 1) + 2 * pow((N - 1),2) * (N - 2);
}

int TSolutionsO(){
    return pow(N, 4)/2 - 5 * (pow(N, 3)/3) + 3 * (pow(N, 2)/2) - N/3;
}
int main(){
    N = 10;
    printf("TC O(N^4): %d\n", TSolutionsB());
    printf("TC O(N) %d\n", TSolutions(N));
    printf("TC O(1) %d\n", TSolutionsO());
    return 0;
}