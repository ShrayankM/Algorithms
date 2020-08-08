#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

struct Stack{
    struct Node* top;
    Stack(){
        top = NULL;
    }

    void push(int data){
        struct Node* n = new Node(data);
        if(top == NULL){
            top = n;
            return;
        }
        n->next = top;
        top = n;
    }

    int pop(){
        if(top == NULL){
            printf("Stack Underflow\n");
            return -1;
        }
        else{
            int data = top->data;
            struct Node* temp = top;
            top = top->next;
            free(temp);
            return data;
        }
    }

    bool empty(){
        if(top == NULL)
            return true;
        return false;
    }

    void display(){
        while(!empty()){
            printf("%d ", pop());
        }
        printf("\n");
    }
};
int main(){

    struct Stack s;
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