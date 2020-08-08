#include<bits/stdc++.h>
using namespace std;

struct Node{
    struct Node* L; struct Node* R;
    int data, height;
    Node(int data){
        this->data = data;
        height = 1;
        L = NULL; R = NULL;
    }
};

struct AVL{
    struct Node* root;
    AVL(){
        root = NULL;
    }

    int Height(struct Node* p){
        int hL, hR;
        hL = (p && p->L) ? p->L->height : 0;
        hR = (p && p->R) ? p->R->height : 0;
        return (hL > hR) ? hL + 1 : hR + 1;
    }

    int bFactor(struct Node* p){
        int hL, hR;
        hL = (p && p->L) ? p->L->height : 0;
        hR = (p && p->R) ? p->R->height : 0;
        return hL - hR;
    }

    Node* LLRotation(struct Node* p){
        struct Node* pL = p->L;
        struct Node* pLR = pL->R;
        p->L = pLR;
        pL->R = p;

        p->height = Height(p);
        pL->height = Height(pL);

        if(root == p)
            root = pL;
        return pL;
    }

    Node* RRRotation(struct Node* p){
        struct Node* pR = p->R;
        struct Node* pRL = pR->L;
        p->R = pRL;
        pR->L = p;

        p->height = Height(p);
        pR->height = Height(pR);

        if(root == p)
            root = pR;
        return pR;
    }

    Node* LRRotation(struct Node* p){
        p->L = RRRotation(p->L);
        p = LLRotation(p);
        return p;
    }

    Node* RLRotation(struct Node* p){
        p->R = LLRotation(p->R);
        p = RRRotation(p);
        return p;
    }

    Node* insert(struct Node* p, int key){
        if(p == NULL){
            struct Node* t = new Node(key);
            return t;
        }
        if(p->data > key)
            p->L = insert(p->L, key);
        else
            p->R = insert(p->R, key);
        p->height = Height(p);

        if(bFactor(p) == 2 && bFactor(p->L) == 1)
            return LLRotation(p);
        if(bFactor(p) == -2 && bFactor(p->R) == -1)
            return RRRotation(p);
        if(bFactor(p) == 2 && bFactor(p->L) == -1)
            return LRRotation(p);
        if(bFactor(p) == -2 && bFactor(p->R) == 1)
            return RLRotation(p);
        return p;
    }

    Node* InorderSucc(struct Node* p){
        while(p && p->L != NULL)
            p = p->L;
        return p;
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
        p->height = Height(p);
        if(bFactor(p) == 2 && (bFactor(p->L) == 0 || bFactor(p->L) == 1))
            return LLRotation(p);
        if(bFactor(p) == 2 && bFactor(p->L) == -1)
            return LRRotation(p);
        if(bFactor(p) == -2 && (bFactor(p->R) == 0 || bFactor(p->R) == -1))
            return RRRotation(p);
        if(bFactor(p) == -2 && bFactor(p->R) == 1)
            return RLRotation(p);
        return p;
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
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 30);

    //tree.insert(tree.root, 7);
    //tree.insert(tree.root, 12);
    //tree.insert(tree.root, 14);

    tree.insert(tree.root, 35);
    tree.insert(tree.root, 26);
    tree.insert(tree.root, 25);

    tree.insert(tree.root, 27);
    tree.root = tree.deleteNode(tree.root, 25);

    tree.root = tree.deleteNode(tree.root, 20);
    tree.root = tree.deleteNode(tree.root, 10);
    tree.root = tree.deleteNode(tree.root, 35);
    //tree.root = tree.deleteNode(tree.root, 10);
    tree.preorder(tree.root);
    cout << "\n";
    return 0;
}