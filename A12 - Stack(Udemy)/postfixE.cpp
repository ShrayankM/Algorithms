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
    char* postFix = new char[(s.size() + 1) * 2];
    stack<char>st;
    int k = 0;
    for(int i = 0; s[i] != '\0'; ){
        if(s[i] >= '1' && s[i] <= '9'){
            postFix[k++] = s[i++];
            postFix[k++] = ' ';
        }
        else if(s[i] == '(' || st.empty())
            st.push(s[i++]);
        else if(outStack(s[i]) > inStack(st.top()))
            st.push(s[i++]);
        else if(outStack(s[i]) < inStack(st.top())){
            char temp = st.top(); st.pop();
            postFix[k++] = temp;
            postFix[k++] = ' ';
        }
        else if(s[i] == ')'){
            while(!st.empty() && (outStack(')') != inStack(st.top()))){
                char temp = st.top(); st.pop();
                postFix[k++] = temp;
                postFix[k++] = ' ';
            }
            st.pop();
            i++;
        }
    }
    while(!st.empty()){
        postFix[k++] = st.top(); st.pop();
        postFix[k++] = ' ';
    }
    return postFix;
}

int calculate(int a, int b, char t){
    if(t == '+')
        return a + b;
    if(t == '-')
        return a - b;
    if(t == '*')
        return a * b;
    if(t == '/')
        return a / b;
    if(t == '^')
        return pow(a, b);
    return 0;
}

int main(){

    string s = "3*5+6/2+4";  //char exp[] = "100 200 + 2 / 5 * 7 +"; 
    char* post = findPost(s);
    printf("%s\n", post);
    stack<int>st;
    for(int i = 0; post[i] != '\0'; i++){
        if(post[i] == ' ')
            continue;
        else if(isdigit(post[i])){
            int num = 0;
            while(isdigit(post[i])){
                num = num * 10 + (int)post[i] - 48;
                i++;
            }
            i--;
            st.push(num);
        }
        else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int c = calculate(a, b, post[i]);
            st.push(c);
        }
    }
    printf("%d\n", st.top());
    return 0;
}