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

    Node* insert(struct Node* p, int data){
        
        if(p == NULL){
            struct Node* t = new Node(data);
            return t;
        }
        if(p->data == data)
            return NULL;
        if(p->data > data)
            p->L = insert(p->L, data);
        else
            p->R = insert(p->R, data);
        
        return p;
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
            insert(root, data);
        }
    }

    void display(struct Node* t){
        if(t != NULL){
            display(t->L);
            printf("%d ", t->data);
            display(t->R);
        }
    }

    Node* search(struct Node* p, int data){
        if(p == NULL)
            return NULL;
        if(p->data == data)
            return p;
        if(p->data > data)
            return search(p->L, data);
        else
            return search(p->R, data);
    }
};

int main(){
    struct BST tree;
    tree.create();
    tree.display(tree.root);
    printf("\n");

    struct Node* find = tree.search(tree.root, 14);
    if(find)
        printf("Found: %d\n", find->data);
    else
        printf("Not Found\n");
    return 0;
}