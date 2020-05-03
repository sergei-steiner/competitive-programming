#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other

class Solution {
public:
    int mod = 1000000007;
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<long long> a;
        for (int i = 0; i < n; ++i) {
            long long ans = 0;
            for (int j : hats[i]) {
                ans += (1LL << j);
            }
            a.push_back(ans);
        }
        int m = 40;
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));
        dp[0][0] = 1;
        for (int l = 1; l <= m; ++l) {
            for (int i = 0; i < (1 << n); ++i) {
                dp[l][i] = dp[l - 1][i];
                int f = 0;
                int s = 0;
                for (int j = 0; j < n; ++j) {
                    if (i & (1 << j)) {
                        if (a[j] & (1LL << l)) {
                            f ^= (1 << j);
                        } else {
                            s ^= (1 << j);
                        }
                    }
                }
                if (f == 0) continue;
                for (int j = 0; j < n; ++j) {
                    if (i & (1 << j)) {
                        if (a[j] & (1LL << l)) {      
                            long long res = dp[l - 1][i ^ (1 << j)];
                            dp[l][i] += dp[l - 1][i ^ (1 << j)];
                            dp[l][i] %= mod;
                        }
                    }
                }
            }
        }
        
        return dp[m][(1 << n) - 1];
    }
};
    
int main() {

    return 0;
}
