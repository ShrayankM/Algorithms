#include<bits/stdc++.h>
using namespace std;

struct Q{
    vector<int>a;
    void enqueue(int data){
        a.push_back(data);
        sort(a.begin(), a.end());
    }

    void dequeue(){
        if(a.size() == 0){
            printf("Queue is empty\n");
            return;
        }
        int x = a.back();
        a.pop_back();
        printf("Deleted: %d\n", x);
    }
};

int main(){
    struct Q q;
    int A[] = {23, 6, 78, 99, 2, 34, 100, 5};
    int N = sizeof(A)/sizeof(int);

    for(int i = 0; i < N; i++)
        q.enqueue(A[i]);
    q.dequeue();
    q.enqueue(1000);
    q.dequeue();
    return 0;
}