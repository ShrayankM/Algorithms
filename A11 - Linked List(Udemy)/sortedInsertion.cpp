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

    void insert(int data){
        struct Node* T = head;
        if(data <= T->data){
            insertHead(data);
            return;
        }
        while(T->next && T->next->data <= data)
            T = T->next;
        struct Node* n = new Node(data);
        n->next = T->next;
        T->next = n;
    }
    /**
     * ? BubbleSort 
     * */
    void sorting(){
        struct Node* i = head;
        while(i){
            struct Node* j = i->next;
            while(j){
                if(j->data < i->data){
                    int t = j->data;
                    j->data = i->data;
                    i->data = t;
                }
                j = j->next;
            }
            i = i->next;
        }
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
    for(int i = 10; i >= 1; i--)
        L.create(i * 2);

    L.sorting();
    L.display(L.head);
    L.insert(1);
    L.insert(7);
    L.insert(23);
    L.display(L.head);
    return 0;
}