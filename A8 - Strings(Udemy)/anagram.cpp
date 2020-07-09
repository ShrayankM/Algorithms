#include<bits/stdc++.h>
using namespace std;

int findLength(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

void check_anagram(char a[], char b[]){
    if(findLength(a) != findLength(b)){
        cout << "Not Anagrams" << "\n";
        return;
    }
    else{
        sort(a, a + findLength(a));
        sort(b, b + findLength(b));
        for(int i = 0, j = 0; (a[i] != '\0' && b[j] != '\0'); i++, j++){
            if(a[i] != b[j]){
                cout << "Not Anagrams" << "\n";
                return;
            }
        }
        cout << "Anagrams" << "\n";
    }
    return;
}

void check_anagramHash(char a[], char b[]){
    if(findLength(a) != findLength(b)){
        cout << "Not Anagrams" << "\n";
        return;
    }
    else{
        int H[130];
        for(int i = 0; i < 130; i++)
            H[i] = 0;
        for(int i = 0; a[i] != '\0'; i++)
            H[a[i]]++;
        for(int i = 0; b[i] != '\0'; i++)
            H[b[i]]--;
        
        for(int i = 0; i < 130; i++){
            if(H[i] != 0){
                cout << "Not Anagrams" << "\n";
                return;
            }
        }
        cout << "Anagrams" << "\n";
    } 
    return;
}
int main(){
    char a[] = "qwwerytuiopp"; char b[] = "qrytuiopwpew"; char c[] = "qwertyuiop";

    /** 
     * ? Using Sorting TC is O(NlogN) to sort the 2 strings 
     * */
    check_anagram(a, b);
    check_anagram(a, c);

    /** 
     * ? Using Hashing TC is O(5N) 
     * */
    
    check_anagramHash(a, b);
    check_anagramHash(a, c);
    return 0;
}