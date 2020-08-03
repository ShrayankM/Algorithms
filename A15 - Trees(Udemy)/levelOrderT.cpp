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

    void preorder(){
        struct Node* t = root;
        stack<Node*>st;
        printf("\n Preorder: ");
        while(t != NULL || !st.empty()){
            if(t != NULL){
                printf("%d ", t->data);
                st.push(t);
                t = t->L;
            }
            else{
                t = st.top(); st.pop();
                t = t->R;
            }
        }
        printf("\n");
    }

    void levelOrder(){
        //struct Node* t = root;
        queue<Node*>Q; Q.push(root);
        printf("\n LeveL Order: ");
        while(!Q.empty()){
            struct Node* t = Q.front(); Q.pop();
            printf("%d ", t->data);
            if(t->L != NULL)
                Q.push(t->L);
            if(t->R != NULL)
                Q.push(t->R);
        }
        printf("\n");
    }
};

int main(){
    struct BT tree;
    tree.create();
    tree.preorder();
    tree.levelOrder();
    return 0;
}