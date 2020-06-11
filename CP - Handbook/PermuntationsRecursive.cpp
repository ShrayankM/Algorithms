#include<cstdio>
#include<vector>
using namespace std;

int N;
vector<bool>T(N + 1, false);
vector<int>P; int count = 0;
void generateP(int A[]){
    if(P.size() == N){
        count++;
        for(int i = 0; i < P.size(); i++)
            printf("%d ", P[i]);
        printf("\n");
        return;
    }
    for(int j = 0; j < N; j++){
        if(T[j])
            continue;
        T[j] = true;
        P.push_back(A[j]);
        generateP(A);
        P.pop_back();
        T[j] = false;
    }
}
int main(){
    int array[] = {1, 2, 3, 4, 5, 6};
    N = 6;
    generateP(array);
    printf("Total Permutations: %d\n", count);
    return 0;
}