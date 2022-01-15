#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/remove-duplicate-letters/
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans; // "stack"
        unordered_map<char, int> cnt; // for simplicity, can be a vector
        unordered_set<char> used; // again, for simplicity
        for (char ch : s) {
            ++cnt[ch];
        }
        for (char ch : s) {
            // skip used
            if (used.count(ch)) {
                --cnt[ch];
                continue;
            }
            // pop
            while (!ans.empty() && ans.back() >= ch && cnt[ans.back()] > 0) {
                used.erase(ans.back());
                ans.pop_back();
            }
            // push
            ans.push_back(ch);
            --cnt[ch];
            used.insert(ch);
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
