#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst

// speading up C(n, k) with help of arrays

class Solution {
public:
    int mod = 1000000007;
    using int64 = long long;
    vector<vector<int>> C_dp;
    int C(int n, int k) {
        if (k < 0) return 0;
        if (k > n) return 0;
        if (n == 0) return 1; // k = 0
        if (C_dp[n][k] >= 0) return C_dp[n][k];
        int64 ans = (C(n - 1, k - 1) + C(n - 1, k));
        if (ans >= mod) ans -= mod;
        C_dp[n][k] = ans;
        return ans;
    }
    int64 count(vector<int>& nums) {
        if (nums.empty()) return 1;
        vector<int> left;
        vector<int> right;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        int64 ans = C(left.size() + right.size(), left.size());
        
        ans *= count(left);
        ans %= mod;
        
        ans *= count(right);
        ans %= mod;
        return ans;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size() + 1;
        C_dp.assign(n, vector<int>(n, -1));
        return ((count(nums) - 1) % mod + mod) % mod;
    }
};
    
int main() {

    return 0;
}
