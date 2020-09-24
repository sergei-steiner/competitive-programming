#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points
// doable in O(n^3) with Hungarian
// still O(2^n * n * m) here 

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size();
        int m = cost[0].size();
        int inf = 1000000000;
        vector<vector<int>> dp((1 << n), vector<int> (m + 1, inf));
        dp[0][0] = 0;
        for(int j = 1; j <= m; ++j) {
            for (int i = 0; i < (1 << n); ++i) {
                for (int k = 0; k < n; ++k) {
                    if (i & (1 << k)) {
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << k)][j] + cost[k][j - 1]);
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << k)][j - 1] + cost[k][j - 1]);
                    }
                }
            }
            for (int i = 0; i < (1 << n); ++i) {
                for (int k = 0; k < n; ++k) {
                    if (i & (1 << k)) {
                        
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << k)][j]);
                    }
                }
            }
        }
        return dp[(1 << n) - 1][m];
    }
};

int main() {

    return 0;
}
