#include<bits/stdc++.h>
using namespace std;

struct Stack{
    vector<int>A;
    int top;
    Stack(){
        top = -1;
    }

    void push(int data){
        top++;
        A.push_back(data);
    }

    int pop(){
        if(A.size() == 0){
            printf("Stack UnderFlow\n");
            return -1;
        }
        int data = A[top--];
        A.pop_back();
        return data;
    }

    bool empty(){
        if(A.size() == 0)
            return true;
        return false;
    }

    void display(){
        while(!empty())
            printf("%d ", pop());
        printf("\n");
    }
};

int main(){

    struct Stack s;
    s.pop();
    int A[] = {23, 45, 2, 10, 11, 15, 36, 57};
    int N = sizeof(A)/sizeof(int);
    for(int i = 0; i < N; i++)
        s.push(A[i]);
    
    s.pop();
    s.push(77); s.push(66); s.push(55); s.push(88);
    s.pop();
    s.display();
    return 0;
}