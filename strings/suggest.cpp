#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/search-suggestions-system

struct Node {
    map<char, Node*> next;

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
    vector<string> cache;
    string pattern;
    Node* Root = nullptr;
    Node* cur = nullptr;
    
    /** Initialize your data structure here. */
    Trie() {
        Root = new Node();
        cur = Root;
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
    
    vector<string> get_ans(Node* root, string prefix, int cnt = 3) {
        if (root == nullptr) return {};
        vector<string> ans;
        if (cnt == 0) return {};
        if (root-> Finish) {
            ans.push_back(prefix);
            --cnt;
        }
        for (auto [ch, next_root] : root->next) {
            if (cnt == 0) break;
            for (string& add : get_ans(next_root, prefix + ch, cnt)) {
                if (cnt == 0) break;
                ans.push_back(add);
                --cnt;
            }
        }
        
        return ans;
    }
    
    vector<string> next(char ch) {
        if (cur == nullptr) return {};
        if (cur->next.find(ch) == cur->next.end()) {
           cur = nullptr;
           return {};
        }
        if (cur->next.size() == 1 && !cache.empty() && !cur-> Finish) {
            cur = cur->next[ch ];
            pattern += ch;
            return cache;
        }
        cur = cur->next[ch ];
        pattern += ch;
        cache = get_ans(cur, pattern);
        return cache;
    } 
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for (string& s : products) trie.insert(s);
        vector<vector<string>> ans;
        for (char ch : searchWord) {
            ans.emplace_back(trie.next(ch));
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
