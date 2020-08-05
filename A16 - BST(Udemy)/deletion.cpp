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

    Node* insert(struct Node* t, int data){
        if(t == NULL){
            struct Node* p = new Node(data);
            return p;
        }
        if(t->data > data)
            t->L = insert(t->L, data);
        else
            t->R = insert(t->R, data);
        
        return t;
    }

    void inorder(struct Node* t){
        if(t != NULL){
            inorder(t->L);
            cout << t->data << " ";
            inorder(t->R);
        }
    }

    Node* InorderSucc(struct Node* r){
        while(r && r->L != NULL)
            r = r->L;
        return r;
    }

    Node* deleteNode(struct Node* p, int key){
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
            struct Node* succ = InorderSucc(p->R);
            p->data = succ->data;
            p->R = deleteNode(p->R, succ->data);
        }
        return p;
    }
};

int main(){
    struct BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 65);
    tree.insert(tree.root, 80);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 67);
    tree.insert(tree.root, 55);
    tree.insert(tree.root, 57);
    //cout << "Hello";

    tree.root = tree.deleteNode(tree.root, 20);
    tree.inorder(tree.root);
    cout << "\n";

    tree.root = tree.deleteNode(tree.root, 50);
    tree.inorder(tree.root);
    cout << "\n";
    return 0;
}