#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/palindrome-removal

// given a string, one can remove any palindromic substring
// return the minimal number of removals to remove the whole string

class Solution {
public:
    int minimumMoves(vector<int>& a) {
        int n = a.size();
        int inf = 1000000000;
        vector<vector<int>> dp(n, vector<int> (n, inf));
        for (int i = 0; i < n; ++i) dp[i][i] = 1;
        for (int i = 0; i + 1 < n; ++i) {
            dp[i][i + 1] = 2;
            if (a[i] == a[i + 1]) dp[i][i + 1] = 1;
        }
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i + l <= n; ++i) {
                int j = i + l - 1;
                if (a[i] == a[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                for (int k = i; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
    
int main() {

    return 0;
}
