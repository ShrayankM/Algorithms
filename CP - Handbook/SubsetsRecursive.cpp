#include<cstdio>
#include<vector>
using namespace std;

vector<int>Set; int count = 0;
void generateSubset(int K, int N){
    if(K == N + 1){
        count++;
        for(int i = 0; i < Set.size(); i++)
            printf("%d ", Set[i]);
        printf("\n");
        return;
    }
    Set.push_back(K);
    generateSubset(K + 1, N);
    Set.pop_back();
    generateSubset(K + 1, N);
}
int main(){
    int N = 10;
    generateSubset(1, N);
    printf("Total Subsets: %d\n", count);
    return 0;
}