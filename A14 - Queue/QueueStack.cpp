#include<bits/stdc++.h>
using namespace std;

struct Q{
    stack<int>s1, s2;
    void enqueue(int data){
        s1.push(data);
    }

    void dequeue(){
        if(s1.empty() && s2.empty()){
            printf("Queue Empty\n");
            return;
        }
        if(s2.empty()){
            while(!s1.empty()){
                int data = s1.top(); s1.pop();
                s2.push(data);
            }
            printf("Deleted: %d \n", s2.top());
            s2.pop();
        }
        else{
            printf("Deleted: %d \n", s2.top());
            s2.pop();
        }
    }
};

int main(){
    struct Q q;
    int A[] = {23, 6, 78, 65, 99};
    int N = sizeof(A)/sizeof(int);

    for(int i = 0; i < N; i++)
        q.enqueue(A[i]);
    q.dequeue();
    q.enqueue(100);
    q.dequeue();
    q.enqueue(1000);
    for(int i = 0; i < N; i++)
        q.enqueue(A[i]);
    q.dequeue();
    q.enqueue(99);
    for(int i = 0; i < 5; i++)
        q.dequeue();

    return 0;
}
