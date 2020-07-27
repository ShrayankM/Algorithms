#include<bits/stdc++.h>
using namespace std;

struct Q{
    int size;
    int front, rear;
    int *A;
    Q(int size){
        this->size = size;
        front = rear = 0;
        A = new int[size];
    }

    void enqueue(int data){
        if((rear + 1)%size == front)
            printf("Queue is Full\n");
        else{
            rear = (rear + 1)%size;
            A[rear] = data;
        }
    }

    void dequeue(){
        if(front == rear)
            printf("Queue is Empty\n");
        else{
            front = (front + 1)%size;
            int x = A[front];
            A[front] = -1;
            printf("Deleted: %d\n", x);
        }
    }

    void display(){
        int p = (front + 1)%size;
        for(; p != rear; p = (p + 1)%size)
            printf("%d ", A[p]);
        printf("%d ", A[rear]);
        printf("\n");
    }
};

int main(){
    struct Q q(7);
    q.dequeue();
    for(int i = 1; i <= 4; i++)
        q.enqueue(i * 2);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(100); q.enqueue(99); q.enqueue(77);
    q.display();
    q.dequeue(); q.dequeue();
    q.display();
    return 0;
}