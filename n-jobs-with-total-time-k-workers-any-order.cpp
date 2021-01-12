#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs
// n = jobs.size()

// my solution: O(k * 3^n)

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int inf = 1000000000;
        vector<vector<int>> sum(k, vector<int> (1 << n, 0));
        for (int l = 0; l < k; ++l) {
            for (int i = 0; i < (1 << n); ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i & (1 << j)) {
                        sum[l][i] += jobs[j];
                    }
                }
            }
        }
        vector<vector<int>> dp(k, vector<int> (1 << n, inf));
        for (int i = 0; i < (1 << n); ++i) {
            dp[0][i] = sum[0][i];
        }
        for (int l = 1; l < k; ++l) {
            for (int i = 0; i < (1 << n); ++i) {
                for (int s = i; ; s = (s - 1) & i) {
                    dp[l][i] = min(dp[l][i], max(dp[l - 1][i ^ s], sum[l][s]));
                    if (s == 0) break;
                }
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};
    
int main() {

    return 0;
}
