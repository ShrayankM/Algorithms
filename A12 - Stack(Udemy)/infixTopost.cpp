#include<bits/stdc++.h>
using namespace std;

int pre(char t){
    if(t == '+' || t == '-')
        return 1;
    else if(t == '*' || t == '/')
        return 2;
    else if(t == '^')
        return 3;
    else
        return -1;
}

char* findPost(string s){                     //char* findPost(char s[])
    char* postFix = new char[s.size() + 1];  //char* postFix = new char[strlen(s) + 1];
    stack<char>st;
    int k = 0;
    for(int i = 0; s[i] != '\0'; ){
        if(s[i] >= 'a' && s[i] <= 'z')
            postFix[k++] = s[i++];
        else{
            if(st.empty() || s[i] == '(')
                st.push(s[i++]);
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    char temp = st.top();
                    postFix[k++] = temp;
                    st.pop();
                }
                st.pop();
                i++;
            }
            else if(pre(s[i]) > pre(st.top()))
                st.push(s[i++]);
            else if(pre(s[i]) <= pre(st.top())){
                char temp = st.top();
                postFix[k++] = temp;
                st.pop();
            }
            else{
                char temp = st.top();
                postFix[k++] = temp;
                st.pop();
            }
        }
    }
    while(!st.empty()){
        postFix[k++] = st.top();
        st.pop();
    }
    return postFix;
}
int main(){

    //char s[] = "a+b*(c^d-e)^(f+g*h)-i";
    //char s[] = "a+b*c/d";
    //string s = "a+b*(c^d-e)^(f+g*h)-i";
    vector<string>s = {"a+b*(c^d-e)^(f+g*h)-i", "a+b*c-d/e*f",
                       "(a+b*c-d)/(e*f)"};
    for(auto str: s)
        printf("%s\n", findPost(str));
    return 0;   
}