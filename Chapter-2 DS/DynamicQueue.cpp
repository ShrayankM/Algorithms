#include<bits/stdc++.h>
using namespace std;
struct Queue{
	vector<int>Q;
	int front , rear;
	Queue(){
		front = -1;
		rear = -1;
	}
	void enqueue(int d){
		if(front == -1 && rear == -1){
			front = 0; rear = 0;
		}
		else
			rear++;
		Q.push_back(d);
	}

	int dequeue(){
		int d = Q[front];
		if(front == rear){
			Q.clear();
			front = -1;
			rear = -1;
		}
		else
			front++;
		return d;
	}

	bool isEmpty(){
		if(front == -1 && rear == -1)
			return true;
		else
			return false;
	}
};
int main(){
	Queue q;
	for(int i=1;i<=10;i++)
		q.enqueue(i);
	while(!q.isEmpty())
		printf("%d ", q.dequeue());
	return 0;
}
