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

    int count(){
        int c = 0;
        struct Node* T = head;
        while(T){
            c++;
            T = T->next;
        }
        return c;
    }

    int sum(){
        int sum = 0;
        struct Node* T = head;
        while(T){
            sum += T->data;
            T = T->next;
        }
        return sum;
    }

    int Max(){
        int m = 0;
        struct Node* T = head;
        while(T){
            m = max(m, T->data);
            T = T->next;
        }
        return m;
    }

};

int main(){
    struct LinkedList L;
    for(int i = 1; i <= 10; i++)
        L.insert(i * 2);
    L.display();
    printf("Count: %d\n", L.count());
    printf("Sum: %d\n", L.sum());
    printf("Max: %d\n", L.Max());
    return 0;
}