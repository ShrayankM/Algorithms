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

struct LL{
    struct Node* head;
    LL(){
        head = NULL;
    }

    void insert(int data){
        struct Node* n = new Node(data);
        if(head == NULL){
            head = n;
            return;
        }
        struct Node* t = head;
        while(t->next != NULL)
            t = t->next;
        t->next = n;
    }

    void display(){
        struct Node* t = head;
        while(t){
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }

    void findMid(){
        struct Node* p = head;
        struct Node* q = head;
        while(q){
            q = q->next;
            if(q) q = q->next;
            if(q) p = p->next;
        }

        printf("%d\n", p->data);
    }
};

int main(){

    struct LL L;
    int A[] = {23, 4, 67, 89, 1, 27, 44, 56};
    int N = sizeof(A)/sizeof(int);

    for(int i = 0; i < N; i++)
        L.insert(A[i]);
    L.display();
    L.findMid();
    return 0;
}