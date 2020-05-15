#include<bits/stdc++.h>
using namespace std;
struct DQueue{
	list<int>DQ;
	void pushFront(int d){
		DQ.push_front(d);
	}

	void pushBack(int d){
		DQ.push_back(d);
	}

	int popFront(){
		auto p = DQ.begin();
		int d = *p;
		DQ.pop_front();
		return d;
	}

	int popBack(){
		auto p = DQ.end();
		p--;
		int d = *p;
		DQ.pop_back();
		return d;
	}
	bool isEmpty(){
		if(DQ.begin() == DQ.end())
			return true;
		else
			return false;
	}
};
int main(){
	DQueue dq;
	for(int i=1;i<=10;i++)
		dq.pushFront(i);
	for(int i=11;i<=20;i++)
		dq.pushBack(i);
	while(!dq.isEmpty())
		printf("%d ", dq.popBack());
	printf("\n");
	for(int i=11;i<=20;i++)
		dq.pushBack(i);
	while(!dq.isEmpty())
		printf("%d ", dq.popFront());
	printf("\n");
	return 0;
}
