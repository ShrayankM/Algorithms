#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct Trie {

    struct Trie *children[ALPHABET_SIZE];
    int freq[ALPHABET_SIZE];
    bool isEnd;

    Trie() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = NULL;
            freq[i] = 0;
        }
        isEnd = false;
    }
};

void insert(struct Trie *root, string key) {
    struct Trie *p = root;
    for (int i = 0; i < key.size(); i++) {

        int index = key[i] - 'a';
        if (!p->children[index]) {
            p->children[index] = new Trie();
            p->freq[index] = 1;
        }
        else  {
            p->freq[index]++;
        }                   
        p = p->children[index];
    }
    p->isEnd = true;
}

bool search(struct Trie *root, string key) {
    struct Trie *p = root;

    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';

        if (!p->children[index]) return false;
        else p = p->children[index];
    }

    return (p != NULL && p->isEnd);
}

int partial(struct Trie *root, string key) {
    struct Trie *p = root;
    int freqCnt = 0;
    for (int i = 0; i < key.size(); i++) {
        int index = key[i] - 'a';

        if (!p->children[index]) return false;
        else { 
            freqCnt = p->freq[index];
            p = p->children[index]; 
        }
    }
    if (p != NULL) return freqCnt;
    return 0;
}

int main(){

    struct Trie *root = new Trie();
    string keys[] = {"hacker", "hackerrank"};

    int n = 2;

    for (int i = 0; i < n; i++) {
        insert(root, keys[i]);
    }

    // cout << search(root, "hacker") << "\n";
    cout << partial(root, "hacker") << "\n";
    
    return 0;
}