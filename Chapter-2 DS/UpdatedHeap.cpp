#include<bits/stdc++.h>
using namespace std;
struct Heap{
	int* array; int N; int N2;
	Heap(int N){
		array = new int[N+1];
		this->N = N;
	}
	void insertArray(int arr[],int N){
		int j = 1;
		for(int i=0;i<N;i++)
			array[j++] = arr[i];
	}

	void heapify(int i,int N){
		int parent = i;
		int Lchild = 2*i; int Rchild = (2*i + 1);
		if(Lchild <= N && array[Lchild] > array[parent])
			parent = Lchild;

		if(Rchild <= N && array[Rchild] > array[parent])
			parent = Rchild;

		if(parent != i){
			int T = array[i];
			array[i] = array[parent];
			array[parent] = T;
			heapify(parent,N);
		}
	}

	void buildHeap(){
		for(int i=(int)floor(N/2);i>0;i--)
			heapify(i,N);
	}

	void displayHeap(){
		for(int i=1;i<=N;i++)
			printf("%d ",array[i]);
		printf("\n");
	}

	void heapSort(){
		for(int i=N;i>0;i--){
			int T = array[i];
			array[i] = array[1];
			array[1] = T;
			heapify(1,i-1);
		}
	}

	void updatekey(int i,int d){
		array[i] = d;
		heapify(1,N);
	}

	void decreasekey(int i,int d){
		array[i] -= d;
		heapify(1,N);
	}

	void deleteKey(int i){
		int* NArray = new int[N-1];
		int j = 1; int k = 1;
		for(;j<i;j++)
			NArray[j] = array[k++];
		k = i + 1;
		for(;k<N;k++)
			NArray[j++] = array[k];

		this->N = N - 1;
		for(int i=1;i<N;i++)
			array[i] = NArray[i];

		heapify(1,N);

	}
};
int main(){
	int A[] = {10,20,40,3,15,60,28,50,46,34};
	int N = 10;
	Heap H(N);
	H.insertArray(A,N);

	H.buildHeap();
	H.displayHeap();
	//H.heapSort();

	//H.displayHeap();

	H.updatekey(3,72);
	H.displayHeap();

	H.deleteKey(7);
	H.displayHeap();

	H.decreasekey(3,2);
	H.displayHeap();
	return 0;
}
