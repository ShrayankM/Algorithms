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
            printf("Enter Left node data: ");
            scanf("%d", &data);
            struct Node* p = Q.front(); Q.pop();
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

    void preorder(){
        struct Node* t = root;
        stack<Node*>st;
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

    void inorder(){
        struct Node* t = root;
        stack<Node*>st;
        while(t != NULL || !st.empty()){
            if(t != NULL){
                st.push(t);
                t = t->L;
            }
            else{
                t = st.top(); st.pop();
                printf("%d ", t->data);
                t = t->R; 
            }
        }
        printf("\n");
    }

    void inorder(struct Node* t){
        if(t != NULL){
            inorder(t->L);
            printf("%d ", t->data);
            inorder(t->R);
        }
    }

    void postorder(struct Node* t){
        if(t != NULL){
            postorder(t->L);
            postorder(t->R);
            printf("%d ", t->data);
        }
    }

    void recursiveT(){
        printf("Preorder: ");
        preorder(root); 
        printf("\n");

        printf("Inorder: ");
        inorder(root); 
        printf("\n");

        printf("Postorder: ");
        postorder(root); 
        printf("\n");
    }

    void iterative(){
        printf("Preorder: ");
        preorder(); 

        printf("Inorder: ");
        inorder(); 
    }
};

int main(){
    struct BT tree;
    tree.create();
    tree.recursiveT();

    printf("\n");
    tree.iterative();
    return 0;
}