#include<bits/stdc++.h>
using namespace std;

void compare_string(char A[], char B[]){
    int i, j;
    for(i = 0, j = 0; (A[i] != '\0' && B[j] != '\0'); i++, j++)
        if(A[i] != B[j])
            break;
    if(A[i] == B[j])
        printf("A = B\n");
    else if(A[i] > B[j])
        printf("A > B\n");
    else
        printf("A < B\n");
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

void compare_caseI(char A[], char B[]){
    makeLowerCase(A); makeLowerCase(B);
    compare_string(A, B);
}

bool check_palindrome(char A[]){
    int i = 0, j = findLength(A) - 1;
    for( ; i < j; i++, j--){
        if(A[i] != A[j])
            return false;
    }
    return true;
}

int main(){

    char A[] = "Paint"; char B[] = "Painter"; char C[] = "Painter"; char D[] = "Painting";
    char E[] = "paiNT"; char F[] = "PAInTeR"; char G[] = "paiNTER"; char H[] = "pAiNTinG";
    char P1[] = "abbbccdaadccbbba"; char P2[] = "abbbadccdbbba";
    //compare_string(A, B);
    //compare_string(B, C);
    //compare_string(C, D);
    //compare_string(D, A);

    compare_string(A, E);
    compare_string(B, F);

    compare_caseI(A, E);
    if(check_palindrome(P1))
        printf("Is Palindrome\n");
    else
        printf("Not A Palindrome\n");
    
    if(check_palindrome(P2))
        printf("Is Palindrome\n");
    else
        printf("Not A Palindrome\n");
    return 0;
}