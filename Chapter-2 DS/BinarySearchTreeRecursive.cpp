#include<bits/stdc++.h>
using namespace std;
struct Node{
	Node* left; Node* right; int data;
	Node(){
		data = 0; left = NULL; right = NULL;
	}
	Node(int d){
		data = d; left = NULL; right = NULL;
	}
};
struct BST{
	Node* ROOT;
	BST(){
		ROOT = NULL;
	}

	Node* insertNode(Node* P,int d){
		if(P == NULL)
			return new Node(d);
		if(d < P->data)
			P->left = insertNode(P->left,d);
		if(d > P->data)
			P->right = insertNode(P->right,d);
		return P;
	}
	void InorderDisplay(Node* P){
		if(P == NULL)
			return;
		else{
			InorderDisplay(P->left);
			printf("%d ",P->data);
			InorderDisplay(P->right);
		}
	}
	Node* search_key(Node* P,int d){
		if(P == NULL)
			return NULL;
		else if(P->data == d)
			return P;
		else{
			if(P->data > d)
				return search_key(P->left,d);
			else
				return search_key(P->right,d);
		}
	}
	Node* findMin(Node* P){
		while(P->left != NULL)
			P = P->left;
		return P;
	}

	Node* findMax(Node* P){
		while(P->right != NULL)
			P = P->right;
		return P;
	}

	Node* deleteNode(Node* P,int K){
		if(K < P->data)
			P->left = deleteNode(P->left,K);
		else if(K > P->data)
			P->right = deleteNode(P->right,K);
		else{
			if(P->left == NULL && P->right == NULL)
				return NULL;
			else if(P->left == NULL && P->right)
				return P->right;
			else if(P->left && P->right == NULL)
				return P->left;
			else{
				Node* temp = findMin(P->right);
				P->data = temp->data;
				P->right = deleteNode(P->right,temp->data);
			}
		}
		return P; 
	}
};
int main(){
	int array[] = {15,23,6,71,50,4,7,5,45,67,21,18,99,32,11,8,57,63,1,22};
	int N = 20;
	struct BST tree;
	for(int i=0;i<20;i++)
		tree.ROOT = tree.insertNode(tree.ROOT,array[i]);
	tree.InorderDisplay(tree.ROOT);
	printf("\n");

	int F = 63;
	Node* Found = tree.search_key(tree.ROOT,F);
	if(Found)
		printf("%d Found\n", F);
	else
		printf("%d Not Found\n", F);
	Node* MIN = tree.findMin(tree.ROOT);
	Node* MAX = tree.findMax(tree.ROOT);

	printf("MAX:%d MIN:%d\n",MAX->data,MIN->data);

	tree.deleteNode(tree.ROOT,18);
	tree.deleteNode(tree.ROOT,15);
	tree.deleteNode(tree.ROOT,67);
	tree.InorderDisplay(tree.ROOT);
	printf("\n");

	return 0;
}
