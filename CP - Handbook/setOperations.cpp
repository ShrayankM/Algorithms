#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    int A[] = {1, 3, 4, 8, 10, 23, 26};
    int B[] = {3, 6, 8, 9, 10, 22, 26};

    int N = 7;
    int x = 0, y = 0;
    for(int i = 0; i < N; i++){
        x = x | (1 << A[i]);
        y = y | (1 << B[i]);
    }
    //Set Intersection
    int c = x & y;
    for(int j = 0; j < 32; j++)
        if(c & (1 << j))
            printf("%d ", j);
    printf("\n");

    //Set Union
    c = x | y;
    for(int j = 0; j < 32; j++)
        if(c & (1 << j))
            printf("%d ", j);
    printf("\n");

    //Set Difference
    c = x & (~y);
    for(int j = 0; j < 32; j++)
        if(c & (1 << j))
            printf("%d ", j);
    printf("\n");
    return 0;
}