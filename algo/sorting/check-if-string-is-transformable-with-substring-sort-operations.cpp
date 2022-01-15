#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations

class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<int> cnt(10, 0);
        for (char ch : s) {
            ++cnt[ch - '0'];
        }
        for (char ch : t) {
            --cnt[ch - '0'];
        }
        for (int i = 0; i < 10; ++i) {
            if (cnt[i] != 0) return false;
        }
        vector<vector<int>> a(10);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            a[s[i] - '0'].push_back(i);
        }
        for (int j = n - 1; j >= 0; --j) {
            int d = t[j] - '0';
            for (int i = d + 1; i < 10; ++i) {
                if (!a[i].empty() && a[i].back() > a[d].back()) {
                    return false;
                }
            }
            a[d].pop_back();
        }
        return true;
    }
};
    
int main() {

    return 0;
}
