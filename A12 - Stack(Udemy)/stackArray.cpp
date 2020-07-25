#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int A[10]; int N;
    int top;
    Stack(){
        top = -1;
        N = 10;
    }

    void push(int data){
        if(top == N - 1){
            printf("Stack Overflow\n");
            return;
        }
        top++;
        A[top] = data;
    }

    bool empty(){
        if(top == -1)
            return true;
        return false;
    }

    int pop(){
        if(top == -1){
            printf("Stack Underflow\n");
            return -1;
        }
        return A[top--];
    }

    void display(){
        while(!empty()){
            printf("%d ", pop());
        }
        printf("\n");
    }
};

int main(){
    struct Stack s1;
    int A[] = {23, 45, 2, 10, 11, 15, 36, 57};
    int N = sizeof(A)/sizeof(int);
    for(int i = 0; i < N; i++)
        s1.push(A[i]);
    
    s1.pop();
    s1.push(77); s1.push(66); s1.push(55); s1.push(88);
    s1.pop();
    s1.display();
    return 0;
}