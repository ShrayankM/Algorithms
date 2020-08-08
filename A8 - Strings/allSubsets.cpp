#include<bits/stdc++.h>
using namespace std;

int findLength(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

void subsets(char s[], int k){
    static vector<char>S;
    if(k == findLength(s)){
        if((int)S.size() == 0){
            cout << "()" << "\n";
            return;
        }
        cout << "(";
        for(int i = 0; i < (int)S.size(); i++)
            cout << S[i];
        cout << ")";
        cout << "\n";
        return;
    }
    S.push_back(s[k]);
    subsets(s, k + 1);
    S.pop_back();
    subsets(s, k + 1);
}
int main(){
    char s[] = "abc";

    /** 
     * ? Basic all possible subsets using extra static vector
     * ! TC O(2 ^ N)
     * */
    
    subsets(s, 0);
    return 0;
}