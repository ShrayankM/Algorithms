#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data; Node* left; Node* right;
	Node(){
		data = 0; left = NULL; right = NULL; 
	}
	Node(int d){
		data = d; left = NULL; right = NULL; 
	}
};
struct BST{
	Node* ROOT;
	vector<int>Sorted;
	BST(){
		ROOT = NULL;
	}
	void insertNode(int d){
		Node* P = new Node(d);
		if(ROOT == NULL)
			ROOT = P;
		else{
			Node* ptr = ROOT;
			while(1){
				if(ptr->data > d){
					if(ptr->left == NULL){
						ptr->left = P;
						break;
					}
					else
						ptr = ptr->left;
				}
				else if(ptr->data <= d){
					if(ptr->right == NULL){
						ptr->right = P;
						break;
					}
					else
						ptr = ptr->right;
				}
			}
		}
	}
	void InOrder(Node* P){
		if(P == NULL)
			return;
		else{
			InOrder(P->left);
			printf("%d ",P->data);
			InOrder(P->right);
		}
	}

	void PreOrder(Node* P){
		if(P == NULL)
			return;
		else{
			printf("%d ",P->data);
			PreOrder(P->left);
			PreOrder(P->right);
		}
	}
	bool FindData(int d){
		Node* P = ROOT;
		if(P->data == d)
			return true;
		else{
			while(1){
				if(P->data > d){
					if(P->data == d)
						return true;
					else if(P->left == NULL)
						return false;
					else
						P = P->left;
				}
				else{
					if(P->data == d)
						return true;
					else if(P->right == NULL)
						return false;
					else
						P = P->right;
				}
			}
		}
	}
	Node* FindDataPTR(int d){
		Node* P = ROOT;
		if(P->data == d)
			return P;
		else{
			while(1){
				if(P->data > d){
					if(P->data == d)
						return P;
					else if(P->left == NULL)
						return NULL;
					else
						P = P->left;
				}
				else{
					if(P->data == d)
						return P;
					else if(P->right == NULL)
						return NULL;
					else
						P = P->right;
				}
			}
		}
	}

	void SortTree(Node* P){
		if(P == NULL)
			return;
		else{
			SortTree(P->left);
			Sorted.push_back(P->data);
			SortTree(P->right);
		}
	}

	int findSuccessor(Node* P){
		if(P->right != NULL){
			P = P -> right;
			while(P->left != NULL)
				P = P -> left;
			return P->data;
		}
		else
			return -1;
	}
};
int main(){
	int array[] = {15,23,6,71,50,4,7,5,45,67,21,18,99,32,11,8,57,63,1,22};
	int N = 20;
	struct BST tree;
	for(int i=0;i<N;i++)
		tree.insertNode(array[i]);
	printf("PreOrder Traversal\n");
	tree.PreOrder(tree.ROOT);
	printf("\n");
	//tree.InOrder(tree.ROOT);
	//printf("\n");
	int E = 23;
	bool found = tree.FindData(E);
	if(found)
		printf("Element %d found\n",E);
	else
		printf("Not Found\n");

	tree.SortTree(tree.ROOT);
	vector<int>::iterator i = tree.Sorted.begin();
	printf("InOrder Traversal(Sorted)\n");
	for(;i != tree.Sorted.end();i++)
		printf("%d ",*i);
	printf("\n");

	int MIN = tree.Sorted[0];
	int MAX = tree.Sorted[tree.Sorted.size()-1];
	printf("MAX:%d MIN:%d\n", MAX,MIN);

	int S = 71;
	Node* P = tree.FindDataPTR(S);
	if(P){
		int SS = tree.findSuccessor(P);
		if(SS == -1)
			printf("NO Successor\n");
		else
			printf("%d is Successor of %d\n", SS,S);
	}
	else
		printf("Element Not Present in Tree\n");
	return 0;
}
