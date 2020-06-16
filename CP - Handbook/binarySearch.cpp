#include<cstdio>
#include<algorithm>
using namespace std;

int binarySearch(int A[], int L, int R, int K){
    if(L <= R){
        int M = (L + R)/2;
        if(A[M] == K)
            return M;
        if(A[M] > K)
            return binarySearch(A, L, M - 1, K);
        return binarySearch(A, M + 1, R, K);
    }
    return -1;
}

void display(int A[], int N){
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    int A[] = {45, 4, 67, 12, 78, 3, 2, 16, 21, 79, 78, 45, 64, 55};
    int N = sizeof(A)/sizeof(int);
    int K;
    sort(A, A + N);
    display(A, N);
    printf("Enter Element to Find: \t"); scanf("%d", &K);
    if(binarySearch(A, 0, N - 1, K) != -1)
        printf("%d Found\n", K);
    else
        printf("%d Not Found\n", K);
    return 0;
}