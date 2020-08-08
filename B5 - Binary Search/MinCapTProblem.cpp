#include<cstdio>
#include<algorithm>
using namespace std;

const int Nmax = 10001;
int G[Nmax]; int N, K;
int sumOf(){
    int sum = 0;
    for(int i = 1; i <= N; i++)
        sum += G[i];
    return sum;
}

int numOfRides(int C){
    int sum = 0, K = 1;
    for(int i = 1; i <= N; i++){
        sum += G[i];
        if(sum > C){
            K++; sum = G[i];
        }
    }
    return K; 
}
int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
        scanf("%d", &G[i]);
    
    int C = *max_element(G, G + (N + 1)); int S = sumOf();
    int rides = 0;
    //Optimal O(logS * N)
    while(C <= S){
        int M = (C + S)/2;
        if(numOfRides(M) <= K)
            S = M - 1;
        else
            C = M + 1;
    }
    //Brute Force O(S * N)
    /*
    while(C <= S){
        rides = numOfRides(C);
        if(rides == K)
            break;
        C++;
    }*/
    printf("Capacity: %d\n", C);
    return 0;
}

//Problem Statement
/*
N - boxes: G[i] - weight of box i, Transport them using a truck of Capacity C,
in the order they are given. Sum of the weights of the boxes can't exceed C.
Find the minimum capacity C such that we can move all boxes using maximum K transports.else

Example: N = 6, K = 3, G[] = [7, 3, 2, 3, 1, 4] Answer:8 */

//Input File
/*
6 3
7 3 2 3 1 4
*/