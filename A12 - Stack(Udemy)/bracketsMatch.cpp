#include<bits/stdc++.h>
using namespace std;

bool type(char t){
    if(t == '{' || t == '}')
        return 1;
    else if(t == '(' || t == ')')
        return 2;
    else
        return 3;
}

void check(string s){
    stack<char>st; int i;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            st.push(s[i]);
            continue;
        }
        if(st.empty())
            break;
        char t = st.top(); st.pop();
        if(type(t) != type(s[i]))
            break;
    }
    if(st.empty() && s[i] == '\0')
        printf("Brackets Balanced\n");
    else
        printf("Brackets Unbalanced\n");
}
int main(){

    vector<string>b = {"[]", "{}{}{}", "[({()()})][()]", "{", "[](){()((("};
    for(int i = 0; i < (int)b.size(); i++)
        check(b[i]);
    return 0;
}