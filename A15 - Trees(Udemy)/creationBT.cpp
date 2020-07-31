#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* L; struct Node* R;
    Node(int data){
        this->data = data;
        L = NULL; R = NULL;
    }
};

struct BT{
    struct Node* root;
    BT(){
        root = NULL;
    }

    void create(){
        int data;
        queue<Node*>Q;
        printf("Enter root node data: ");
        scanf("%d", &data);
        struct Node* t = new Node(data);
        root = t;
        Q.push(root);
        while(!Q.empty()){
            struct Node* p = Q.front(); Q.pop();
            printf("Enter Left node data: ");
            scanf("%d", &data);
            if(data != -1){
                struct Node* t = new Node(data);
                p->L = t;
                Q.push(p->L);
            }

            printf("Enter Right node data: ");
            scanf("%d", &data); 
            if(data != -1){
                struct Node* t = new Node(data);
                p->R = t;
                Q.push(p->R);
            }
        }
    }

    void preorder(struct Node* t){
        if(t != NULL){
            printf("%d ", t->data);
            preorder(t->L);
            preorder(t->R);
        }
    }

    void preorderIterative(){
        stack<Node*>st;
        struct Node* t = root;
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
};

int main(){
    struct BT tree;
    tree.create();
    tree.preorder(tree.root);
    printf("\n");
    tree.preorderIterative();
    return 0;
}