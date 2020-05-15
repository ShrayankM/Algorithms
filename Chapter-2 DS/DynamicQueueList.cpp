#include<bits/stdc++.h>
using namespace std;
struct Queue{
	list<int>Q;
	int front;
	Queue(){
		front = 0;
	}
	void enqueue(int d){
		Q.push_back(d);
	}

	int dequeue(){
		auto p = Q.begin();
		for(int i=0;i<front;i++)
			p++;
		int d = *p;
		front++;
		return d;
	}

	bool isEmpty(){
		auto p = Q.begin();
		for(int i=0;i<front;i++)
			p++;
		if(p == Q.end())
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
	printf("\n");
	return 0;
}
