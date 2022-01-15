#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/pizza-with-3n-slices
// https://www.quora.com/Given-a-pizza-with-3n-slices-e-g-9-12-repeatedly-pick-a-slice-save-the-size-of-this-slice-When-you-do-this-the-slice-on-the-left-goes-to-someone-on-the-left-and-the-slice-on-the-right-goes-to-someone-on-the-right-Repeat-this-process-until-no-slices-are-left-How-can-you-write-a-program-to-find-a-list

class Solution {
public:
    int solve(vector<int> a) {
        int n = a.size();
        int m = (n + 1) / 3;
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int> (m + 1, 0));
        dp[0][1] = a[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (i > 1 && dp[i][j] < dp[i - 2][j - 1] + a[i]) {
                    dp[i][j] = dp[i - 2][j - 1] + a[i];
                }
                if (i == 1 && j == 1) dp[i][j] = max(dp[i][j], a[i]);
            }
        }
        return dp[n - 1][m];
    }
    
    int maxSizeSlices(vector<int>& b) {
        vector<int> a = b;
        a.pop_back();
        int ans = solve(a);
        a.clear();
        for (int i = 1; i < b.size(); ++i) a.push_back(b[i]);
        ans = max(ans, solve(a));
        return ans;
       
    }
};

int main() {

    return 0;
}
