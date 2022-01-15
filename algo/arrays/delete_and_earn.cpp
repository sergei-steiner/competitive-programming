#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/delete-and-earn
// all about the trick to ignore +1 completely

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> b;
        if (nums.empty()) return 0;
        for (int num : nums) ++b[num];
        vector<int> a;
        vector<int> cnt;
        for (auto [k, v] : b) {
            a.push_back(k);
            cnt.push_back(v);
        }
        int n = a.size();
        vector<int> dp(n, 0);
        dp[0] = a[0] * cnt[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1];
            int add = a[i] * cnt[i];
            if (a[i - 1] + 1 == a[i]) {
                if (i > 1) add += dp[i - 2];
            } else {
                add += dp[i - 1];
            }
            dp[i] = max(dp[i], add);
        }
        return dp[n - 1];
    }
};
    
int main() {

    return 0;
}
