#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/paint-house-ii/
// O(nk)

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        int inf = 1000000000;
        vector<vector<int>> dp(n, vector<int>(k, inf));
        for (int j = 0; j < k; ++j) {
            dp[0][j] = costs[0][j];
        }
        
        for (int i = 1; i < n; ++i) {
            int first = -1;
            int second = -1;
            for (int j = 0; j < k; ++j) {
                if (first == -1 || dp[i - 1][j] < dp[i - 1][first]) {
                    second = first;
                    first = j;
                } else if (second == -1 || dp[i - 1][j] < dp[i - 1][second]) {
                    second = j;
                }
            }
            for (int j = 0; j < k; ++j) {
                if (j != first) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][first] + costs[i][j]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][second] + costs[i][j]);
                }
            }   
        }
        return *min_element(begin(dp[n - 1]), end(dp[n - 1]));
    }
};
    
int main() {

    return 0;
}
