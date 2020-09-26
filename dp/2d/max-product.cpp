#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix

class Solution {
public:
    int maxProductPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        long long inf = 1000000000000L;
        vector<vector<long long>> dp1(n, vector<long long> (m, inf));
        vector<vector<long long>> dp2(n, vector<long long> (m, -inf));
        int mod = 10000000007;
        dp1[0][0] = a[0][0];
        dp2[0][0] = a[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0) {
                    dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] * a[i][j]);
                    dp1[i][j] = min(dp1[i][j], dp2[i - 1][j] * a[i][j]);
                    dp2[i][j] = max(dp2[i][j], dp1[i - 1][j] * a[i][j]);
                    dp2[i][j] = max(dp2[i][j], dp2[i - 1][j] * a[i][j]);
                }
                if (j > 0) {
                    dp1[i][j] = min(dp1[i][j], dp1[i][j - 1] * a[i][j]);
                    dp1[i][j] = min(dp1[i][j], dp2[i][j - 1] * a[i][j]);
                    dp2[i][j] = max(dp2[i][j], dp1[i][j - 1] * a[i][j]);
                    dp2[i][j] = max(dp2[i][j], dp2[i][j - 1] * a[i][j]);                    
                }
            }
        }
        if (dp2[n - 1][m - 1] < 0) return -1;
        return dp2[n - 1][m - 1] % mod;
    }
};
    
int main() {

    return 0;
}
