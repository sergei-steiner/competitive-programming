#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-score-triangulation-of-polygon
// matrix chain multiplication in disguise

class Solution {
public:
    int minScoreTriangulation(vector<int>& a) {
        int n = a.size();
        int inf = 1000000000;
        vector<vector<int>> dp(n, vector<int> (n, inf));
        for (int i = 0; i < n; ++i) dp[i][i] = 0;
        for (int i = 0; i + 1 < n; ++i) dp[i][i + 1] = 0;
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][ j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
    
int main() {

    return 0;
}
