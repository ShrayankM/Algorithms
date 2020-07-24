#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* prev; struct Node* next;
    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

struct DLL{
    struct Node* head;
    struct Node* tail;
    DLL(){
        head = NULL;
        tail = NULL;
    }

    void create(int data){
        struct Node* n = new Node(data);
        if(head == NULL){
            head = n; 
            tail = n;
            return;
        }
        n->prev = tail;
        tail->next = n;
        tail = n;
    }

    void display(){
        struct Node* t = head;
        while(t){
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }

    void insert(int pos, int data){
        struct Node* n = new Node(data);
        if(pos == 1){
            n->next = head;
            head->prev = n;
            head = n;
            return;
        }
        struct Node* t = head;
        for(int i = 1; i < pos - 1 && t; i++)
            t = t->next;
        
        if(t != NULL && t != tail){
            n->next = t->next;
            n->prev = t;
            t->next->prev = n;
            t->next = n;
        }
        else if(t != NULL && t == tail){
            n->prev = t;
            t->next = n;
            tail = n;
        }
    }

    void deleteNode(int pos){
        if(pos == 1){
            struct Node* temp = head;
            head->next->prev = NULL;
            head = head->next;
            free(temp);
            return;
        }
        struct Node* t = head;
        for(int i = 1; i < pos; i++)
            t = t->next;
        struct Node* temp = t;
        if(t == tail){
            t->prev->next = NULL;
            tail = t->prev;
            free(temp);
            return;
        }
        t->prev->next = t->next;
        t->next->prev = t->prev;
        free(temp); 
    }

    void reverse(struct Node* q, struct Node* p){
        if(p != NULL)
            reverse(p, p->next);
        else if(p == tail){
            head = p;
            p->next = q;
            p->prev = NULL;
            return;
        }
        p->prev = p->next;
        p->next = q;
        /*if(q == NULL){
            tail = q;
        }*/

    }
};

int main(){
    struct DLL L;
    int A[] = {12, 23, 4, 56, 78, 9, 3, 47, 65};
    int N = sizeof(A)/sizeof(int);

    for(int i = 0; i < N; i++)
        L.create(A[i]);
    L.insert(1, 100);
    L.insert(5, 66);
    L.insert(N + 4, 100);
    L.display();

    L.deleteNode(1);
    L.deleteNode(5);
    L.deleteNode(9);
    L.deleteNode(8);
    L.display();

    L.reverse(NULL, L.head);
    L.display();
    return 0;
}