#include<bits/stdc++.h>
using namespace std;

/**
 * ? struct Element (Represent single values in sparse Matrix)
 * */
struct Element{
    int r, c, x;
};

/**
 * ? struct Sparse
 * * n, m (total_rows, total_columns)
 * ? c (non-zero values)
 * ! data array stores all non-zero elements in the form of struct Element
 * */
struct Sparse{
    int n, m, c;
    struct Element* data;
};

void create(struct Sparse *A){
    /**
     * * printf("Enter No. of Rows and Columns: ");
     * */
    scanf("%d %d\n", &A->n, &A->m);
    /**
     * * printf("Enter No. of non-zero Elements: ");
     * */
    scanf("%d\n", &A->c);
    int N = A->c;
    A->data = new Element[A->c + 1];
    /**
     * * printf("Enter %d non-zero Elements:\n", N);
     * */
    for(int i = 0; i < N; i++)
        scanf("%d %d %d\n", &A->data[i].r, &A->data[i].c, &A->data[i].x);
}

void displayMatrix(struct Sparse A){
    int k = 0;
    for(int i = 1; i <= A.n; i++){
        for(int j = 1; j <= A.m; j++){
            if(A.data[k].r == i && A.data[k].c == j)
                printf("%d ", A.data[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

void add(struct Sparse A, struct Sparse B){
    struct Sparse C;
    C.n = A.n; C.m = A.m;
    int N = A.c + B.c;
    //printf("%d\n", N);
    C.data = new Element[N + 1];
    int i, j, k = 0;
    while(i < A.c && j < B.c){
        if(A.data[i].r < B.data[j].r)
            C.data[k++] = A.data[i++]; //data
        else if(A.data[i].r > B.data[j].r)
            C.data[k++] = B.data[j++]; //data
        else{
            if(A.data[i].c < B.data[j].c)
                C.data[k++] = A.data[i++]; 
            else if(A.data[i].c > B.data[j].c)
                C.data[k++] = B.data[j++]; 
            else{
                C.data[k] = A.data[i];
                C.data[k].x = A.data[i].x + B.data[j].x;
                k++; i++; j++;
            }
        }
    }
    for(; i < A.c; i++)
        C.data[k++] = A.data[i];
    for(; j < B.c; j++)
        C.data[k++] = B.data[j];
    displayMatrix(C);
}

int main(){

    /**
     * ! 3 Column Representation of Sparse Matrix
     * */

    freopen("input.txt", "r", stdin);
    struct Sparse A;
    create(&A);
    //displayMatrix(A);
    struct Sparse B;
    create(&B);
    //displayMatrix(A);
    add(A, B);
    return 0;
}

/**
 * TODO Input file for Program
 * ? n, m (rows, columns)
 * * c (non-zero elements)
 * ? r, c, x (row_no, col_no, value)
 * */

/*
5 6
5
1 4 2
2 2 4
4 1 8
4 5 5
5 4 7
5 6
6
1 1 1
1 4 2
2 2 4
4 1 8
4 5 5
5 4 7
*/