#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/implement-trie-prefix-tree

struct Node {
    unordered_map<char, Node*> next;

    bool Finish = false;
    
    Node* add(char ch) {
        if (next.find(ch) == next.end()) {
            next[ch] = new Node();
        }
        return next[ch];
    }
};


class Trie {
public:
    
    Node* Root = nullptr;
    /** Initialize your data structure here. */
    Trie() {
        Root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto root = Root;
        for (char ch : word) {
            root = root->add(ch);
        }
        root->Finish = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto root = Root;
        for (char ch : word) {
            if (root->next.find(ch) == root->next.end()) {
                return false;
            } else {
            root = root->next[ch];
            }
        }
        return root->Finish;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto root = Root;
        for (char ch : prefix ) {
            if (root->next.find(ch) == root->next.end()) {
                return false;
            } else {
                root = root->next[ch];
            }
        }
        return true;
        
    }
};

int main() {

    return 0;
}
