#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/stone-game-v

class Solution {
public:
    vector<int> a;
    vector<vector<int>> dp;
    int solve(int i, int j) {
        if (i == j) return 0;
        if (dp[i][j] >= 0) return dp[i][j];
        int ans = 0;
        for (int k = i; k < j; ++k) {
            int sum1 = a[k];
            if (i > 0) sum1 -= a[i - 1];
            int sum2 = a[j] - a[k];
            if (sum1 >= sum2) {
                ans = max(ans, solve(k + 1, j) + sum2);
            }
            if (sum1 <= sum2) {
                ans = max(ans, solve(i, k) + sum1);
            }
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& arr) {
        a = arr;
        int n = a.size();
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }
};
    
int main() {

    return 0;
}
