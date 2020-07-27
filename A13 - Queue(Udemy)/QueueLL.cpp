#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int data){
        this->data = data;
    }
};

struct Q{
    struct Node* front;
    struct Node* rear;
    Q(){
        front = rear = NULL;
    }

    void enqueue(int data){
        struct Node* n = new Node(data);
        if(n == NULL)
            printf("Queue is FULL\n");
        else{
            if(front == NULL && rear == NULL)
                front = rear = n;
            else{
                rear->next = n;
                rear = n;
            }
        }
    }

    void dequeue(){
        if(front == NULL && rear == NULL){
            printf("Queue is Empty\n");
            return;
        }
        if(front == rear){
            printf("Delete: %d\n", front->data);
            front = rear = NULL;
        }
        else{
            struct Node* temp = front;
            printf("Delete: %d\n", front->data);
            front = front->next;
            free(temp);
        }
    }

    void display(){
        struct Node* t = front;
        while(t){
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }
};

int main(){

    struct Q q;
    for(int i = 1; i <= 10; i++)
        q.enqueue(i * 2);
    for(int i = 1; i <= 10; i++)
        q.dequeue();
    for(int i = 1; i <= 10; i++)
        q.enqueue(i);
    q.display();
    return 0;
}