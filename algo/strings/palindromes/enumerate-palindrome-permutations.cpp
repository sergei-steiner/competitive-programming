#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/palindrome-permutation-ii

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        map<char, int> a;
        for (char ch : s) {
            ++a[ch];
        }
        int cnt = 0;
        char ch;
        for (auto [k, v] : a) {
           if (v % 2 == 1) {
               ch = k;
               ++cnt;
           }
        }
        if (cnt > 1) return {};
        string p;
        for (auto [k, v] : a) {
           for (int i = 0; i < v / 2; ++i) {
               p.push_back(k);
           }
        }
        if (p.empty()) {
            if (cnt == 0) return {};
            return { string(1, ch) };
        }
        vector<string> ans;
        while (true) {
            string str;
            for (int i = 0; i < p.size(); ++i) str.push_back(p[i]);
            if (cnt) str.push_back(ch);
            for (int i = p.size() - 1; i >= 0; --i) str.push_back(p[i]);
            ans.push_back(str);
            if (!next_permutation(begin(p), end(p))) break;
        }
        return ans;
    }
};


int main() {

    return 0;
}
