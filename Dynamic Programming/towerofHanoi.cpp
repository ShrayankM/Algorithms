#include<bits/stdc++.h>
using namespace std;

int moves = 0;

void TOH(int n, char s, char e, char d) {
    if (n > 0) {
        TOH(n - 1, s, d, e);
        cout << "Move disk from " << s << " to " << d << "\n";
        moves++;
        TOH(n - 1, e, s, d);
    }
}

int main(){

    TOH(20, 'S', 'E', 'D');
    cout << "Total Moves: " << moves << "\n";
    return 0;
}