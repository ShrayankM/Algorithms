#include<cstdio>
#include<algorithm>
using namespace std;

void find_MissingHash(int A[], int N){
    int M = *max_element(A, A + N);
    int* T = new int[M + 1];
    for(int i = 0; i < N; i++)
        T[A[i]]++;
    
    for(int i = 1; i <= M; i++)
        if(T[i] == 0)
            printf("%d ", i);
    printf("\n");
}

void find_Missing(int A[], int N){
    int diff = A[0];
    for(int i = 1; i < N; i++){
        if(A[i] - i != diff){
            while(diff < A[i] - i){
                printf("%d ", diff + i);
                diff++;
            }
        }
    }
    printf("\n");
}

int main(){
    int A[] = {1, 5, 3, 6, 2, 9, 13, 25, 34, 39, 44, 48};
    int N = sizeof(A)/sizeof(int);
    sort(A, A + N);

    find_Missing(A, N); //Normal TC = O(N)
    find_MissingHash(A, N); //Using Hashing TC = O(N) but lots of storage required
    return 0;
}