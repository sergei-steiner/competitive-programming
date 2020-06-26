#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/last-stone-weight-ii/

class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n = a.size();
        int shift = 2500;
        int m = 5000;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
        dp[0][shift] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j - a[i - 1] >= 0 && dp[i - 1][j - a[i - 1]]) dp[i][j] = true;
                if (j + a[i - 1] <= m && dp[i - 1][j + a[i - 1]]) dp[i][j] = true;    
            }
        }
        int ans = 100500;
        for (int i = 0; i <= m; ++i) {
            if (dp[n][i]) ans = min(ans, abs(i - shift));
        }
        return ans;
    }
};

int main() {
    return 0;
}
