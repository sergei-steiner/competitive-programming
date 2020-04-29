#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

// O(n^3)

class Solution {
public:
    vector<bool> used;
    int calc(const vector<vector<int>>& a, int val, int r) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            vector<char> d(2, 0);
            for (int j = 0; j < m; ++j) {
                if (a[r][j] == val) {
                    d[a[i][j]] = 1;
                } else {
                    d[1 - a[i][j]] = 1;
                }
                if (d[0] + d[1] > 1) break;
            }
            if (d[0] + d[1] == 1) {
                ++ans;
                used[i] = true;
            }
        }
        return ans;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        used.assign(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) ans = max(ans, calc(a, 0, i));
        }
        return ans;
        
    }
};
    
int main() {

    return 0;
}
