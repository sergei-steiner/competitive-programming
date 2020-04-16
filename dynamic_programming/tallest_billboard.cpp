#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/tallest-billboard

class Solution {
public:
    int tallestBillboard(vector<int>& a) {
        int n = a.size();
        int shift = 5000;
        int max_val = 5000;
        int inf = 1000000000;
        int m = max_val + shift;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -inf));
        dp[0][shift] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (dp[i - 1][j] > -inf ) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }
                if (j - a[i - 1] >= 0 && dp[i - 1][j - a[i - 1]] > -inf) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]]+ a[i - 1]);
                }
                if (j + a[i - 1] <= m && dp[i - 1][j + a[i - 1]] > -inf) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i - 1]]);
                }
            }
        }
        return dp[n][shift]; 
    }
};

int main() {
}
