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

struct DEQ{
    struct Node* front;
    struct Node* rear;
    DEQ(){
        front = rear = NULL;
    }

    void insert(int data, int pos){
        struct Node* n = new Node(data);
        if(n == NULL){
            printf("Queue is Full\n");
        }
        else{
            if(front == NULL && rear == NULL){
                front = rear = n;
            }
            else{
                if(pos == 0){
                    n->next = front;
                    front = n;
                }
                else{
                    rear->next = n;
                    rear = n;
                }
            }
        }
    }

    void dequeue(int pos){
        if(front == NULL && rear == NULL){
            printf("Queue is Empty\n");
            return;
        }
        if(front == rear){
            printf("Deleted: %d \n", front->data);
            front = rear = NULL;
        }
        else{
            if(pos == 0)
                front = front->next;
            else{
                struct Node* t = front;
                while(t->next != rear)
                    t = t->next;
                rear = t;
                rear->next = NULL;
            }
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
    struct DEQ q;
    q.insert(1, 0); q.insert(100, 1);
    q.insert(2, 0); q.insert(200, 1);
    q.display();
    q.dequeue(0); q.dequeue(1);
    q.display();
    q.dequeue(1);
    q.dequeue(1);
    q.dequeue(1);
    return 0;
}