#include<bits/stdc++.h>
using namespace std;

int outStack(char t){
    if(t == '+' || t == '-')
        return 1;
    else if(t == '*' || t == '/')
        return 3;
    else if(t == '^')
        return 6;
    else if(t == ')')
        return 0; //for ( parenthesis
    else
        return 7;
}

int inStack(char t){
    if(t == '+' || t == '-')
        return 2;
    else if(t == '*' || t == '/')
        return 4;
    else if(t == '^')
        return 5;
    else
        return 0; //for ( parenthesis
}

char* findPost(string s){                     //char* findPost(char s[])
    char* postFix = new char[s.size() + 1];
    stack<char>st;
    int k = 0;
    for(int i = 0; s[i] != '\0'; ){
        if(s[i] >= 'a' && s[i] <= 'z')
            postFix[k++] = s[i++];
        else if(s[i] == '(' || st.empty())
            st.push(s[i++]);
        else if(outStack(s[i]) > inStack(st.top()))
            st.push(s[i++]);
        else if(outStack(s[i]) < inStack(st.top())){
            char temp = st.top(); st.pop();
            postFix[k++] = temp;
        }
        else if(s[i] == ')'){
            while(!st.empty() && (outStack(')') != inStack(st.top()))){
                char temp = st.top(); st.pop();
                postFix[k++] = temp;
            }
            st.pop();
            i++;
        }
    }
    while(!st.empty()){
        postFix[k++] = st.top(); st.pop();
    }
    return postFix;
}
int main(){

    vector<string>s = {"a+b*(c^d-e)^(f+g*h)-i", "a+b*c-d/e*f",
                       "(a+b*c-d)/(e*f)", "((a+b)*c)-d^e^f"};
    for(auto str: s)
        printf("%s\n", findPost(str));
    return 0;   
}