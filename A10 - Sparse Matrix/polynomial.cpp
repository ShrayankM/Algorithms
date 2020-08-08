#include<bits/stdc++.h>
using namespace std;

/** 
 * ? struct Term represents terms in polynomial equation
 * */
struct Term{
    int coeff, expo;
};

/** 
 * ? struct P represents the polynomial equation
 * */
struct P{
    int n;
    struct Term* t;
    P(int n){
        this->n = n;
        t = new Term[n + 1];
    }

    void create(){
        /**
         * * printf("Enter %d, elements: coeff expo\n", n); 
         * */
        for(int i = 0; i < n; i++)
            scanf("%d %d\n", &t[i].coeff, &t[i].expo);
    }

    void display(){
        printf("%dx^%d ",t[0].coeff, t[0].expo);
        for(int i = 1; i < n; i++)
            printf("+ %dx^%d",t[i].coeff, t[i].expo);
        printf("\n");
    }

    void findValue(int x){
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += (t[i].coeff * pow(x, t[i].expo));
        printf("Value of Polynomial for x = %d: %d\n", x, sum);
        printf("\n");
    }

};

struct P* add(struct P* a, struct P* b){
    struct P* sum = new P(a->n + b->n);
    int i = 0, j = 0, k = 0;
    while(i < a->n && j < b->n){
        if(a->t[i].expo == b->t[j].expo){
            sum->t[k].coeff = a->t[i].coeff + b->t[j].coeff;
            sum->t[k].expo  = a->t[i].expo;
            i++; j++; k++; 
        }
        else if(a->t[i].expo > b->t[j].expo)
            sum->t[k++] = a->t[i++];
        else if(a->t[i].expo < b->t[j].expo)
            sum->t[k++] = b->t[j++];
    }

    for(;i < a->n; i++)
        sum->t[k++] = a->t[i++];
    for(;j < b->n; j++)
        sum->t[k++] = b->t[j++];
    
    sum->n = k;
    return sum;
    //sum.display();
}

int main(){

    freopen("input.txt", "r", stdin);
    struct P* a; struct P* b; struct P* c; int d, x;

    /**
     * * printf("Enter the no. of elements for P1: "); 
     * */
    scanf("%d\n", &d);
    a = new P(d);
    a->create();  a->display();
    /**
     * * printf("Enter the value of x: "); 
     * */
    scanf("%d\n", &x);
    a->findValue(x);
    /**
     * * printf("Enter the no. of elements for P2: "); 
     * */
    scanf("%d\n", &d);
    b = new P(d);
    b->create();  b->display();
    /**
     * * printf("Enter the value of x: "); 
     * */
    scanf("%d\n", &x);
    b->findValue(x);

    c = add(a, b);
    c->display(); 
    c->findValue(x);
    return 0;
}

/**
 * TODO Input Files for the program
 * ? n (no. of terms in polynomial)
 * * coeff expo (term coefficient and exponent)
 * ! x (value of x) to solve equation
 * */

/*
6
3 6
2 4
8 3
9 2
4 1
5 0
2
4
5 6
6 5
8 3
4 1
2
*/