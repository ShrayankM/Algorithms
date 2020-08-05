#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data, height;
    struct Node* L; struct Node* R;
    Node(int data){
        this->data = data;
        L = NULL; R = NULL; height = 1;
    }
};

struct AVL{
    struct Node* root;
    AVL(){
        root = NULL;
    }

    int findHeight(struct Node* p){
        int hL, hR;
        hL = (p && p->L) ? p->L->height:0;
        hR = (p && p->R) ? p->R->height:0;
        return (hL > hR) ? hL + 1 : hR + 1;
    }
    
    int bFactor(struct Node* p){
        int hL, hR;
        hL = (p && p->L) ? p->L->height:0;
        hR = (p && p->R) ? p->R->height:0;
        return hL-hR;
    }

    Node* LLRotation(struct Node* p){
        struct Node* pL = p->L;
        struct Node* pLR = p->L->R;
        pL->R = p;
        p->L = pLR;

        p->height = findHeight(p);
        pL->height = findHeight(pL);
        
        if(root == p)
            root = pL;
        return pL;
    }

    Node* RRRotation(struct Node* p){
        struct Node* pR = p->R;
        struct Node* pRL = p->R->L;
        pR->L = p;
        p->R = pRL;

        p->height = findHeight(p);
        pR->height = findHeight(pR);

        if(root == p)
            root = pR;
        return pR;
    }

    Node* LRRotation(struct Node* p){
        p->L = RRRotation(p->L);
        p->L->height = findHeight(p->L);
        p = LLRotation(p);
        p->height = findHeight(p);
        return p;
    }

    Node* RLRotation(struct Node* p){
        p->R = LLRotation(p->R);
        p->R->height = findHeight(p->R);
        p = RRRotation(p);
        p->height = findHeight(p);
        return p;
    }

    Node* insert(struct Node* p, int data){
        if(p == NULL){
            struct Node* t = new Node(data);
            return t;
        }
        if(p->data > data)
            p->L = insert(p->L, data);
        else
            p->R = insert(p->R, data);
        
        p->height = findHeight(p);
        if(bFactor(p) == 2 && bFactor(p->L) == 1)
            return LLRotation(p);
        else if(bFactor(p) == -2 && bFactor(p->R) == -1)
            return RRRotation(p);
        else if(bFactor(p) == 2 && bFactor(p->L) == -1)
            return LRRotation(p);
        else if(bFactor(p) == -2 && bFactor(p->R) == 1)
            return RLRotation(p);
        return p;
    }

    void inorder(struct Node* t){
        if(t != NULL){
            inorder(t->L);
            cout << t->data << " ";
            inorder(t->R);
        }
    }

    void preorder(struct Node* t){
        if(t != NULL){
            cout << t->data << " ";
            preorder(t->L);
            preorder(t->R);
        }
    }
};

int main(){
    struct AVL tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 50);
    tree.insert(tree.root, 25);
    tree.preorder(tree.root);
    cout << "\n";

    tree.inorder(tree.root);
    cout << "\n";
    return 0;
}