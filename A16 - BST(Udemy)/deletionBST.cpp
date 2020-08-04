#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* L;
    struct Node* R;
    Node(int data){
        this->data = data;
        L = NULL;
        R = NULL;
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
        printf("Enter the no. of nodes: ");
        scanf("%d", &n);
        int data;
        printf("Enter the root node data: "); scanf("%d", &data);
        struct Node* temp = new Node(data);
        root = temp;
        for(int i = 0; i < n - 1; i++){
            printf("Enter the node data: "); scanf("%d", &data);
            insert(root, data);
        }

    }

    void display(struct Node* p){
        if(p != NULL){
            display(p->L);
            printf("%d ", p->data);
            display(p->R);
        }
    }

    Node* inorderSucc(struct Node* t){
        while(t && t->L != NULL)
            t = t->L;
        return t;
    }

    Node* search(struct Node* t, int key){
        if(t == NULL)
            return NULL;
        if(t->data == key)
            return t;
        if(t->data > key)
            return search(t->L, key);
        else
            return search(t->R, key);
    }

    Node* deleteNode(struct Node* p, int key){

        if(p == NULL)
            return NULL;
        if(p->data > key)
            p->L = deleteNode(p->L, key);
        else if(p->data < key)
            p->R = deleteNode(p->R, key);
        else{
            if(p->L == NULL){
                struct Node* temp = p->R;
                free(p);
                return temp;
            }
            if(p->R == NULL){
                struct Node* temp = p->L;
                free(p);
                return temp;
            }
            struct Node* succ = inorderSucc(p->R);
            p->data = succ->data;
            p->R = deleteNode(p->R, succ->data);
        }
        return p;
    }
};

int main(){
    struct BST tree;
    tree.create();
    tree.display(tree.root);
    printf("\n");
    
    
    if(tree.search(tree.root, 20))
        tree.deleteNode(tree.root, 20);
    
    tree.display(tree.root);
    printf("\n");
    if(tree.search(tree.root, 30))
        tree.deleteNode(tree.root, 30);

    tree.display(tree.root);
    printf("\n");
    if(tree.search(tree.root, 50))
        tree.root = tree.deleteNode(tree.root, 50);
    tree.display(tree.root);
    printf("\n");

    if(tree.search(tree.root, 1))
        tree.root = tree.deleteNode(tree.root, 1);
    tree.display(tree.root);
    printf("\n");
    return 0;
}

/*
                  50
               /     \
             30      70
            /  \    /  \
           20  40  60  80
*/