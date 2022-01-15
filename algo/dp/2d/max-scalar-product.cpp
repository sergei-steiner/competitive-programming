#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/max-dot-product-of-two-subsequences
// very simple, but all about handling negative answers!

class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int inf = 1000000000;
        int ans = -inf;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -inf));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i - 1][j - 1], 0) + a[i - 1] * b[j - 1];
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        return dp[n][m];
    }
};

int main() {

    return 0;
}
