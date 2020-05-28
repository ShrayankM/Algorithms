#include<cstdio>
#include<algorithm>
using namespace std;

const int Nmax = 1001; int N;
int A[Nmax][Nmax], maxLen[Nmax][Nmax];

int maxSquare(){
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(A[i][j] == 1)
                maxLen[i][j] = 1 + min(maxLen[i][j - 1], min(maxLen[i - 1][j], maxLen[i - 1][j - 1]));
            else
                maxLen[i][j] = 0;
            ans = max(ans, maxLen[i][j]);
        }
    }
    return ans;
}
int main(){
    freopen("input.txt", "r",stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &A[i][j]);

    printf("%d\n", maxSquare());
    return 0;
}