#include<cstdio>
#include<algorithm>
using namespace std;

pair<int*, int> Union(int A[], int NA, int B[], int NB){
    int* C = new int[NA + NB];
    sort(A, A + NA); sort(B, B + NB);
    int i, j; int k = 0;
    for(i = 0, j = 0; i < NA, j < NB; j++, i++){
        if(A[i] == A[j])
            C[k++] = A[i];
        else{
            C[k++] = A[i]; C[k++] = A[j];
        }
    }
    while(i < NA)
        C[k++] = A[i++];
    while(j < NB)
        C[k++] = A[j++];
    return make_pair(C, k);
}
pair<int*, int> Intersection(int A[], int NA, int B[], int NB){
    int* C = new int[NA + NB];
    sort(A, A + NA); sort(B, B + NB);
    int i, j; int k = 0;
    for(i = 0, j = 0; i < NA, j < NB; ){
        if(A[i] == B[j]){
            C[k++] = A[i];
            i++; j++;
        }
        else if(A[i] > B[j])
            j++;
        else if(A[i] < B[j])
            i++;
    }
    return make_pair(C, k);
}
pair<int*, int> Difference(int A[], int NA, int B[], int NB){
    int* C = new int[NA + NB];
    sort(A, A + NA); sort(B, B + NB);
    int i, j; int k = 0;
    for(i = 0, j = 0; i < NA, j < NB; ){
        if(A[i] == B[j]){
            i++; j++;
        }
        else if(A[i] > B[j]){
            j++;
        }
        else if(A[i] < B[j]){
            C[k++] = A[i];
            i++;
        }
    }
    return make_pair(C, k);
}
int main(){
    int A[] = {1, 5, 3, 6, 2, 9, 13, 25, 34, 39, 44, 48}; int NA = 12;
    int B[] = {1, 6, 3, 44, 34, 9, 2, 48, 7}; int NB = 9;

    //Set Union
    pair<int*, int>C;
    printf("Set Union: ");
    C = Union(A, NA, B, NB);
    for(int i = 0; i < C.second; i++)
        printf("%d ", C.first[i]);
    printf("\n");

    //Set Intersection
    printf("Set Intersection: ");
    C = Intersection(A, NA, B, NB);
    for(int i = 0; i < C.second; i++)
        printf("%d ", C.first[i]);
    printf("\n");

    //Set Difference
    printf("Set Difference: (A - B) ");
    C = Difference(A, NA, B, NB);
    for(int i = 0; i < C.second; i++)
        printf("%d ", C.first[i]);
    printf("\n");

    printf("Set Difference: (B - A) ");
    C = Difference(B, NB, A, NA);
    for(int i = 0; i < C.second; i++)
        printf("%d ", C.first[i]);
    printf("\n");
    return 0;
}