#include<cstdio>
#include<algorithm>
using namespace std;

void countingSort(int A[], int N){
    int S = *max_element(A, A + N);
    int* T = new int[S];

    for(int i = 0; i < S; i++)
        T[i] = 0;

    for(int i = 0; i < N; i++)
        T[A[i]]++;
    
    int i = 0; int j = 0;
    while(i < S){
        if(T[i] != 0){
            A[j++] = i; T[i]--;
        }
        else
            i++;
    }
}

void display(int A[], int N){
    for(int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(){
    int A[] = {45, 4, 67, 12, 78, 3, 2, 16, 21, 79, 78, 45, 64, 55};
    int N = sizeof(A)/sizeof(int);
    countingSort(A, N);
    display(A, N);
    return 0;
}