#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* L;
    struct Node* R;
    Node(int data){
        this->data = data;
        L = NULL; R = NULL;
    }
};

struct BST{
    struct Node* root;
    BST(){
        root = NULL;
    }

    void insert(int data){
        struct Node* parent; 
        struct Node* r = root;
        while(r != NULL){
             parent = r;
            if(r->data == data)
                return;
            if(r->data > data)
                r = r->L;
            else
                r = r->R;
        }
        struct Node* temp = new Node(data);
        if(parent->data > data)
            parent->L = temp;
        else
            parent->R = temp;
    }

    void create(){
        int n;
        printf("Enter the total no. of nodes ");
        scanf("%d", &n);
        printf("Enter root node data:");
        int data;
        scanf("%d", &data);
        struct Node* t = new Node(data);
        root = t;
        for(int i = 0; i < n - 1; i++){
            printf("Enter node data to be inserted:");
            scanf("%d", &data);
            insert(data);
        }
    }

    void display(struct Node* t){
        if(t != NULL){
            display(t->L);
            printf("%d ", t->data);
            display(t->R);
        }
    }
};

int main(){
    struct BST tree;
    tree.create();
    tree.display(tree.root);
    printf("\n");
    return 0;
}