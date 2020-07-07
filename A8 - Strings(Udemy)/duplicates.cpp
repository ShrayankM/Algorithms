#include<bits/stdc++.h>
using namespace std;

const int Nmax = 50;
int H[Nmax];

void find_duplicates(char s[]){
    for(int i = 0; s[i] != '\0'; i++){
        int c = 1;
        if(s[i] != '0' && s[i] != ' '){
            for(int j = i + 1; s[j] != '\0'; j++){
                if(s[i] == s[j]){
                    c++; s[j] = '0';
                }
            }
        }
        if(c > 1)
            printf("Letter %c: Count %d\n", s[i], c);
    }
}

void find_duplicatesHash(char s[]){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            H[s[i] - 97]++;
        else if(s[i] >= 'A' && s[i] <= 'Z')
            H[s[i] - 65 + 26]++;
    }

    for(int i = 0; i <= 42; i++){
        if(H[i] > 1){
            if(i <= 25)
                printf("Letter %c: Count %d\n", i + 97, H[i]);
            else
                printf("Letter %c: Count %d\n", i + 65 - 26, H[i]);
        }
    }
}

int main(){
    char s[] = "Basics of String Operations Finding Duplicates";
    /** 
     * ? TC of find_duplicates is O(N ^ 2) where N is length of String 
     * */
    //find_duplicates(s);

    /**
     * ? TC of find_duplicatesHash is O(2N) where N is length of String 
     * */
    find_duplicatesHash(s);
    return 0;
}