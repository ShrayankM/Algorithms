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
    LinkedList(){
        head = NULL; 
        tail = NULL;
    }

    void insert(int data){
        struct Node* n = new Node(data);
        if(head == NULL){
            head = n; tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }

    void display(){
        struct Node* T = head;
        while(T){
            printf("%d ", T->data);
            T = T->next;
        }
        printf("\n");
    }
};

void mergeLL(struct Node* f, struct Node* s){
    struct Node* T; struct Node* L;
    if(f->data < s->data){
        T = f; L = f;
        f = f->next; L->next = NULL;
    }
    else{
        T = s; L = s;
        s = s->next; L->next = NULL;
    }
    while(f != NULL && s != NULL){
        if(f->data < s->data){
            L->next = f;
            L = f;
            f = f->next;
            L->next = NULL;
        }
        else{
            L->next = s;
            L = s;
            s = s->next;
            L->next = NULL;
        }
    }
    while(f != NULL){
        L->next = f;
        L = f;
        f = f->next;
    }
    while(s != NULL){
        L->next = s;
        L = s;
        s = s->next;
    }
    struct LinkedList FL;
    FL.head = T; FL.tail = L;
    FL.display();
}

int main(){
    struct LinkedList L1, L2;
    int A[] = {2, 4, 5, 8, 20, 34}; int B[] = {4, 6, 12, 19, 56, 64};
    int _na = sizeof(A)/sizeof(int); 
    int _nb = sizeof(B)/sizeof(int);
    for(int i = 0; i < _na; i++)
        L1.insert(A[i]);
    L1.display();

    for(int i = 0; i < _nb; i++)
        L2.insert(B[i]);
    L2.display();

    mergeLL(L1.head, L2.head);
    return 0;
}