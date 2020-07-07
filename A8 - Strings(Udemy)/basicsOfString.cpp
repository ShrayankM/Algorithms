#include<bits/stdc++.h>
using namespace std;

void makeUpperCase(char s[]){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
    }
}

void makeLowerCase(char s[]){
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >= 65 && s[i] <= 90)
            s[i] += 32;
    }
}

int findLength(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

void stringReverse(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    i--;
    for(int j = 0; j < i; j++, i--){
        char T = s[j];
        s[j] = s[i];
        s[i] = T;
    }
}

pair<int, int> _count(char s[]){
    int v = 0, c = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] =='u'
        || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            v++;
        else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            c++;
    }
    return make_pair(v, c);
}

int countWords(char s[]){
    int c = 0;
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == ' ' && s[i - 1] != ' ')
            c++;
    return c + 1;
}

int main(){

    char s[] = "Basics of String Operation";
    printf("Length of String: %d\n", findLength(s));
    //makeUpperCase(s);
    printf("Uppercase: %s\n", s);
    //makeLowerCase(s);
    printf("Lowercase: %s\n", s);
    //stringReverse(s);
    printf("Reversed String: %s\n", s);
    pair<int, int>C = _count(s);
    printf("Total Vowels: %d Total Consonants: %d\n", C.first, C.second);

    printf("Total Words: %d\n", countWords(s));
    return 0;
}