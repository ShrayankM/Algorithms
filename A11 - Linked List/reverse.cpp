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

    void reverse(){
        struct Node* r; struct Node* q; struct Node* p;
        p = head; q = NULL; r = NULL;
        if(head->next == NULL)
            return;
        
        while(p){
            r = q;
            q = p;
            p = p->next;

            q->next = r;
        }
        head = q;
    }

    void reverseRecursive(struct Node* q, struct Node* p){

        if(p != NULL){
            reverseRecursive(p, p->next);
            p->next = q;
            return;
        }
        head = q;
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

int main(){
    struct LinkedList L;
    for(int i = 1; i <= 10; i++)
        L.insert(i * 2);
    L.display();
    L.reverse();
    L.display();
    
    L.reverseRecursive(NULL, L.head);
    L.display();
    return 0;
}