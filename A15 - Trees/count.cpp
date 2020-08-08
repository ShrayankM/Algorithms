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

struct BT{
    struct Node* root;
    BT(){
        root = NULL;
    }

    void create(){
        printf("Enter root node data: ");
        int data; scanf("%d", &data);
        struct Node* n = new Node(data);
        root = n;
        queue<Node*>Q; Q.push(root);
        while(!Q.empty()){
            struct Node* t = Q.front(); Q.pop();
            printf("Enter Left node data: ");
            scanf("%d", &data);
            if(data != -1){
                struct Node* p = new Node(data);
                t->L = p;
                Q.push(t->L);
            }

            printf("Enter Right node data: ");
            scanf("%d", &data);
            if(data != -1){
                struct Node* p = new Node(data);
                t->R = p;
                Q.push(t->R);
            }
        }
    }

    int count(struct Node* p){
        if(p != NULL){
            int x = count(p->L);
            int y = count(p->R);
            return x + y + 1;
        }
        return 0;
    }

    int cLeaf(struct Node* p){
        if(p != NULL){
            int x = cLeaf(p->L);
            int y = cLeaf(p->R);
            if(p->L == NULL && p->R == NULL)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;
    }

    int I2(struct Node* p){
        if(p != NULL){
            int x = I2(p->L);
            int y = I2(p->R);
            if(p->L != NULL && p->R != NULL)
                return x + y + 1;
            else
                return x + y;
        }
        return 0;
    }

    int I1(struct Node* p){
        if(p != NULL){
            int x = I1(p->L);
            int y = I1(p->R);
            if((p->L != NULL && p->R == NULL) || (p->L == NULL && p->R != NULL))
                return x + y + 1;
            else
                return x + y;
        }
        return 0;
    }

    int height(struct Node* p){
        if(p != NULL){
            int x = height(p->L);
            int y = height(p->R);
            if(x > y)
                return x + 1;
            else
                return y + 1;
        }
        return 0;
    }

};

int main(){
    struct BT tree;
    tree.create();
    printf("Nodes in tree %d\n", tree.count(tree.root));
    printf("Leaf Nodes in tree %d\n", tree.cLeaf(tree.root));
    printf("Nodes with degree 2 in tree %d\n", tree.I2(tree.root));
    printf("Nodes with degree 1 in tree %d\n", tree.I1(tree.root));

    printf("Height of Tree %d\n", tree.height(tree.root));
    return 0;
}