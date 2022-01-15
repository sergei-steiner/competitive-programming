#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits

class Solution {
public:
    vector<int> t;
    int n = 0;
    int cnt(int i) {
        int ans = 0;
        for ( ; i >= 0; i = (i & (i + 1)) - 1) {
            ans += t[i]; 
        }
        return ans;
    }
    void inc(int i) {
        for ( ; i < n; i = i | (i + 1)) {
            ++t[i];
        }
    }
    string minInteger(string s, int k) {
        n = s.size();
        t.assign(n, 0);
        vector<vector<int>> ind(10);
        for (int i = 0; i < n; ++i) {
            ind[s[i] - '0'].push_back(i) ;    
        }
        vector<int> pos(10, 0);
        string ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (pos[j] >= ind[j].size()) {
                    continue;
                }
                int gap = ind[j][pos[j]] - cnt(ind[j][pos[j]]);
                if (gap <= k) {
                    ans.push_back('0' + j);
                    k -= gap;
                    inc(ind[j][pos[j]]);
                    ++pos[j];
                    break;
                }
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
