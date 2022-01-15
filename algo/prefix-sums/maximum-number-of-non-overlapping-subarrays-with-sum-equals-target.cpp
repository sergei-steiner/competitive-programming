#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target

class Solution {
public:
    int maxNonOverlapping(vector<int>& a, int target) {
        unordered_map<int, int> prefix;
        prefix[0] = 0;
        int sum = 0;
        int n = a.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            sum += a[i - 1];
            dp[i] = dp[i - 1];
            if (prefix.count(sum - target)) {
                int j = prefix[sum - target];
                dp[i] = max(dp[i], dp[j] + 1);
            }
            prefix[sum] = i;
        }
        return dp[n];
    }
};

int main() {

    return 0;
}

