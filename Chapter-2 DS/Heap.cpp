#include<bits/stdc++.h>
using namespace std;
struct Heap{
	int* array; int index;
	Heap(int N){
		array = new int[N+1];
		index = 1;
	}
	void insert(int data){
		array[index] = data;
		int I = index;
		while(I != 1){
			int parent = array[(int)floor(I/2)];
			if(array[I] > parent){
				int T = array[I];
				array[I] = parent;
				array[(int)floor(I/2)] = T;
			}
			I = (int)floor(I/2);
		}
		index++;
	}
	void displayHeap(int N){
		for(int i=1;i<=N;i++)
			printf("%d ", array[i]);
		printf("\n");
	}
	void sortHeap(){
		int I = index - 1;
		while(I != 1){
			int MAX = array[1];
			array[1] = array[I];
			array[I] = MAX;
			index--;
			int C = 1;
			while(1){
				if(C*2 > index || (C*2 + 1) > index)
					break;
				int C1 = C*2; int C2 = (C*2)+1;
				if(array[C1] > array[C2]){
					int T = array[C];
					array[C] = array[C1];
					array[C1] = T;
					C = C1;
				}
				else{
					int T = array[C];
					array[C] = array[C2];
					array[C2] = T;
					C = C2;
				}
			}
			I--;
		}
	}
};
int main(){
	int N = 10;
	Heap H(N);
	int A[] = {10,20,40,3,15,60,28,50,46,34};
	//Creating Heap
	for(int i=0;i<N;i++)
		H.insert(A[i]);

	H.displayHeap(N);

	//Sorting Heap
	H.sortHeap();
	H.displayHeap(N);

	return 0;
}
