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

    void insertHead(int data){
        struct Node* n = new Node(data);
        n->next = head;
        head = n;
        c++;
    }

    void insertLast(int data){
        struct Node* n = new Node(data);
        tail->next = n;
        tail = n;
        c++;
    }

    void insertPos(int pos, int data){
        if(pos == 0){
            insertHead(data);
            return;
        }
        if(pos == c){
            insertLast(data);
            return;
        }
        struct Node* T = head;
        for(int i = 0; i < pos - 1; i++)
            T = T->next;
        struct Node* n = new Node(data);
        n->next = T->next;
        T->next = n;
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
    //printf("%d\n", L.c);

    L.insertPos(4, 77);
    L.insertPos(0, 100);
    L.display(L.head);
    return 0;
}