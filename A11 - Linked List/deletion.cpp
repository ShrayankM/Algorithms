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

struct LinkedList{
    struct Node* head;
    struct Node* tail;
    int c;
    LinkedList(){
        head = NULL;
        tail = NULL;
        c = 0;
    }

    void create(int data){
        struct Node* n = new Node(data);
        c++;
        if(head == NULL){
            head = n; tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }

    void deleteHead(){
        struct Node* T = head;
        head = head->next;
        free(T);
    }

    void deletePos(int pos){
        if(pos > c)
            return;
        c--;
        if(pos == 1){
            deleteHead();
            return;
        }
        struct Node* T = head;
        for(int i = 1; i < pos - 1; i++)
            T = T->next;
        struct Node* P = T->next;
        T->next = T->next->next;
        free(P);
    }

    void display(struct Node* head){
        if(head){
            printf("%d ", head->data);
            display(head->next);
            return;
        }
        printf("\n");
    }
};

int main(){
    struct LinkedList L;
    for(int i = 1; i <= 10; i++)
        L.create(i * 2);
    
    //L.deletePos(1);
    L.display(L.head);
    L.deletePos(3);
    //L.deletePos(60);
    L.display(L.head);
    return 0;
}