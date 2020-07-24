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

struct CLL{
    struct Node* head;
    CLL(){
        head = NULL;
    }

    void create(int data){
        struct Node* n = new Node(data);
        if(head == NULL){
            head = n;
            head->next = head;
            return;
        }
        struct Node* p = head;
        while(p->next != head){
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
    }

    void display(){
        struct Node* p = head;
        do{
            printf("%d ", p->data);
            p = p->next;
        }while(p != head);
        printf("\n");
    }

    void insert(int pos, int data){
        struct Node* n = new Node(data);
        struct Node* p = head;
        if(pos == 1){
            while(p->next != head){
                p = p->next;
            }
            n->next = head;
            p->next = n;
            head = n;
            return;
        }
        for(int i = 1; i < pos - 1; i++)
            p = p->next;
        n->next = p->next;
        p->next = n;
    }

    void deleteNode(int pos){
        struct Node* p = head;
        if(pos == 1){
            while(p->next != head)
                p = p->next;
            struct Node* temp = head;
            p->next = head->next;
            head = head->next;
            free(temp);
            return;
        }
        for(int i = 1; i < pos - 1; i++)
            p = p->next;
        p->next = p->next->next;
    }

    void reverse(struct Node* q, struct Node* p){
        if(p->next != head)
            reverse(p ,p->next);
        else{
            p->next = q;
            head = p;
        }
        p->next = q;
        if(!q)
            p->next = head;
    }
};

int main(){
    struct CLL C;
    for(int i = 1; i <= 10; i++)
        C.create(i * 2);
    C.display();
    C.insert(1, 77);
    C.insert(4, 88);
    C.display();
    C.deleteNode(4);
    C.deleteNode(1);
    C.display();

    C.reverse(NULL, C.head);
    C.display();
    return 0;
}