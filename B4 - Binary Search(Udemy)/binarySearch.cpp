#include<cstdio>
#include<algorithm>
using namespace std;

const int Nmax = 1001;
int A[Nmax]; int N; int L, R;

//Iterative O(logN)
int binarySearch(int V){
    int L = 1, R = N;
    while(L <= R){
        int M = (L + R)/2;
        if(A[M] == V)
            return M;
        if(A[M] < V)
            L = M + 1;
        else
            R = M - 1;
    }
    return -1;
}
//Recursive O(logN)
int binarySearchR(int L, int R, int V){
    if(L <= R){
        int M = (L + R)/2;
        if(A[M] == V)
            return M;
        if(A[M] < V)
            return binarySearchR(M + 1, R, V);
        else
            return binarySearchR(L, M - 1, V);
    }
    return -1;
}

void display(){
    for(int i = 1; i <= N; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &A[i]);
    
    sort(A, A + (N + 1));
    //display();
    int Q; scanf("%d", &Q);
    for(int i = 1; i <= Q; i++){
        int V; scanf("%d", &V);
        //Recursive Calls
        if(binarySearchR(0, N, V) != -1)
            printf("Element %d Found:\n", V);
        else
            printf("Element %d Not Found:\n", V);
        //Iterative Calls
        /*
        if(binarySearch(V) != -1)
            printf("Element %d Found:\n", V);
        else
            printf("Element %d Not Found:\n", V);
        */
    }
    return 0;
}