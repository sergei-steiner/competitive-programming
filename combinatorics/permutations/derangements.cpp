#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

// https://leetcode.com/problems/find-the-derangement-of-an-array
// https://oeis.org/A000166

// here are two recurrent formulas from oeis
// but inclusion-exclusion should also work in linear time

class Solution {
public:
    int findDerangement(int n) {
        int mod = 1000000007;
        vector<int64> dp(n + 10, 0);
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]);
            dp[i] %= mod;
        }
        return dp[n];
    }
};

class Solution2 {
public:
    int findDerangement(int n) {
        int mod = 1000000007;
        vector<int64> dp(n + 10, 0);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i * dp[i - 1] + (1 - 2 * (i % 2));
            dp[i] %= mod;
            dp[i] += mod;
            dp[i] %= mod;
        }
        return dp[n];
    }
};
    
int main() {

    return 0;
}
