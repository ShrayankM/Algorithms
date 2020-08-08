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

    void inorder(struct Node* t){
        if(t != NULL){
            inorder(t->L);
            cout << t->data << " ";
            inorder(t->R);
        }
    }
};

Node* generate(int P[], int N){
    int i = 0;
    struct Node* root = new Node(P[i++]);
    struct Node* t = root;

    stack<Node*>st;
    while(i < N){
        if(P[i] < t->data){
            struct Node* temp = new Node(P[i++]);
            t->L = temp;
            st.push(t);
            t = temp;
        }
        else if(P[i] > t->data && st.empty()){
            struct Node* temp = new Node(P[i++]);
            t->R = temp;
            t = temp;
        }
        else if(P[i] > t->data && !st.empty() && st.top()->data > P[i]){
            struct Node* temp = new Node(P[i++]);
            t->R = temp;
            t = temp;
        }
        else{
            t = st.top();
            st.pop();
        }
    }
    return root;
}

int main(){

    int P[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int N = sizeof(P)/sizeof(int);

    struct BST tree;
    tree.root = generate(P, N);
    tree.inorder(tree.root);
    cout << "\n";
    return 0;
}