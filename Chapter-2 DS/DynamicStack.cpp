#include<bits/stdc++.h>
using namespace std;
struct Stack{
	vector<int>S;
	int top;
	Stack(){
		top = -1;
	}
	void push(int d){
		top++;
		S.push_back(d);
	}
	int pop(){
		int d = S[top];
		if(top == 0){
			S.clear();
			top = -1;
		}
		else{
			top--;
			if(top == 0)
				S.resize(1);
			else
				S.resize(top);
		}
		return d;
	}
};
int main(){
	Stack s;
	for(int i=1;i<=10;i++)
		s.push(i);
	for(int i=11;i<=20;i++)
		s.push(i);
	while(!s.S.empty())
		printf("%d\n", s.pop());
	return 0;
}
