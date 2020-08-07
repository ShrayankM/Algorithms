#include<bits/stdc++.h>
using namespace std;

struct Heap{
    vector<int>A;
    int N;
    Heap(){
        A.push_back(-1);
        N = 0;
    }

    void heapify(int parent){
        int Large = parent;
        int L = 2 * parent, R = 2 * parent + 1;

        if(L <= N && A[L] > A[Large])
            Large = L;
        
        if(R <= N && A[R] > A[Large])
            Large = R;
        
        if(Large != parent){
            swap(A[Large], A[parent]);
            heapify(Large);
        }
    }

    void heapify(){
        for(int i = N; i >= 1; i--)
            heapify(i);
    }

    void insert(int key){
        A.push_back(key);
        N++;
        heapify();
    }

    void deleteNode(){
        swap(A[1], A[N]);
        N--;
        heapify(1);
    }

    void sorted(){
        for(int i = 1; i < (int)A.size(); i++)
            printf("%d ", A[i]);
        printf("\n");
    }

    void maxHeap(){
        for(int i = 1; i < (int)A.size(); i++)
            printf("%d ", A[i]);
        printf("\n");
    }
};

int main(){

    int A[] = {-1, 45, 6, 23, 8, 19, 16, 45, 23, 1, 9};
    int N = sizeof(A)/sizeof(int);


    struct Heap H;
    for(int i = 1; i < N; i++)
        H.insert(A[i]);
    
    while(H.N > 1)
        H.deleteNode();
    //H.maxHeap();

    H.sorted();
    return 0;
}