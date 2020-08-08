#include<bits/stdc++.h>
using namespace std;

int c = 0;

int findLength(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

void perm(char s[]){
    static vector<char>P;
    static vector<int>V(findLength(s), 0);
    if((int)P.size() == findLength(s)){
        c++;
        for(int i = 0; i < (int)P.size(); i++)
            cout << P[i];
        cout << "\n";
        return;
    }
    for(int i = 0; s[i] != '\0'; i++){
        if(V[i])
            continue;
        V[i] = 1;
        P.push_back(s[i]);
        perm(s);
        P.pop_back();
        V[i] = 0;
    }
}

void swap(char* a, char* b){
    char T = *a;
    *a = *b;
    *b = T;
}

void perm_swap(char s[], int L, int H){
    if(L == H){
        c++;
        for(int i = 0; s[i] != '\0'; i++)
            cout << s[i];
        cout << "\n";
        return;
    }
    for(int i = L; i < H; i++){
        swap(&s[i], &s[L]);
        perm_swap(s, L + 1, H);
        swap(&s[i], &s[L]);
    }
}
int main(){
    char a[] = "abcd";
    /** 
     * ? Basic all possible permutations using extra vector and visited 
     * ! TC O(N!) 
     * */
    perm(a);
    cout << "Total Permutations: " << c << "\n";
    c = 0;
    /** 
     * ? Permutations using swapping does not use extra space 
     * ! TC O(N!)
     * */
    perm_swap(a,0,findLength(a));
    cout << "Total Permutations: " << c << "\n";
    return 0;
}