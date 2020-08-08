#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

struct CircularDLL{
    struct Node* head;
    struct Node* tail;
    CircularDLL(){
        head = NULL;
        tail = NULL;
    }

    void create(int data){
        struct Node* n = new Node(data);
        if(head == NULL){
            head = n;
            tail = n;
            n->next = n;
            n->prev = n;
            return;
        }
        n->next = head;
        head->prev = n;
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void reverse(){
        struct Node* p = head;
        tail = head;
        while(true){
            struct Node* temp;
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            if(p->prev == head){
                head = p;
                break;
            }
            p = p->prev;   
        }
    }

    void display(){
        struct Node* t = head;
        do{
            printf("%d ", t->data);
            t = t->next;
        }while(t != head);
        printf("\n");
    }
};

int main(){
    struct CircularDLL L;
    int A[] = {23, 4, 5, 67, 8, 12, 67};
    int N = sizeof(A)/sizeof(int);
    for(int i = 0; i < N; i++)
        L.create(A[i]);
    L.display();
    L.reverse();
    L.display();
    return 0;
}