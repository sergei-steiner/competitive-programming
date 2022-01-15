#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-cost-to-cut-a-stick

class Solution {
public:
    int minCost(int N, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(N);
        sort(begin(cuts), end(cuts));
        int n = cuts.size();
        int inf = 1000000000;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> opt(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) opt[i][i] = i;
        for (int i = 0; i + 1 < n; ++i) opt[i][i + 1] = i;
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i + l <= n; ++i) {
                int j = i + l - 1;
                dp[i][j] = inf;
                for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; ++k) {
                    if (dp[i][j] > cuts[j] - cuts[i] + dp[i][k] + dp[k][j]) {
                        dp[i][j] = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                        opt[i][j] = k;               
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
    
int main() {

    return 0;
}
