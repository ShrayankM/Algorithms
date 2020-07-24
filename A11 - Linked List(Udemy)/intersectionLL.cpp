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
};

void findInter(struct Node* F, struct Node* L){
    stack<Node*>s1, s2;
    while(F){
        s1.push(F);
        F = F->next;
    }

    while(L){
        s2.push(L);
        L = L->next;
    }

    while(!s1.empty() && !s2.empty()){
        struct Node* n1 = s1.top(); s1.pop();
        struct Node* n2 = s2.top(); s2.pop();
        printf("%d %d\n", n1->data, n2->data);
        if(n1 != n2){
            printf("Intersection Point: %d\n", n1->next->data);
            break;
        }
    }
}

int main(){

    struct LL L1;
    int A[] = {23, 4, 67, 89, 1, 27, 44, 56};
    int N = sizeof(A)/sizeof(int);

    for(int i = 0; i < N; i++)
        L1.insert(A[i]);
    L1.display();

    int B[] = {-2, -7, -90};

    struct LL L2;
    N = sizeof(B)/sizeof(int);
    for(int i = 0; i < N; i++)
        L2.insert(B[i]);
    L2.display();

    L2.head->next->next->next = L1.head->next->next->next->next;
    L2.display();

    findInter(L1.head, L2.head);
    return 0;
}