#include<cstdio>
#include<math.h>
using namespace std;
//O(N) time complexity
bool isPrime(int N){
    if(N == 0 || N == 1)
        return false;
    for(int i = 2; i < N; i++){
        if(N % i == 0)
            return false;
    }
    return true;
}
/** 
 * * O(sqrt(N)) time complexity 
 */
bool isPrimeSqrt(int N){
    if(N == 0 || N == 1)
        return false;
    for(int i = 2; i < sqrt(N); i++){
        if(N % i == 0)
            return false;
    }
    return true;
}
int main(){
    int N = 13;
    printf("%d\n",isPrime(N));
    printf("%d\n",isPrimeSqrt(N));
    return 0;
}

/** 
 * TODO : refactor this method
 * ? Should this loop end here ? 
 * ! This method is deprecated
 * * Important information
*/
