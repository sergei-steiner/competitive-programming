#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/count-all-possible-routes
// dp one arg up, second arg down

class Solution {
public:
    int mod = 1000000007;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
        dp[start][fuel] = 1;
        for (int f = fuel - 1; f >= 0; --f) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == j) continue;
                    if (f + abs(locations[i] - locations[j]) > fuel) {
                        continue;
                    }
                    dp[i][f] += dp[j][f + abs(locations[i] - locations[j])];
                    if (dp[i][f] >= mod) dp[i][f] -= mod;
                }
            }
        }
        int ans = 0;
        for (int f = 0; f <= fuel; ++f) {
            ans += dp[finish][f];
            if (ans >= mod) ans -= mod;
        }
        
        return ans;
    }
};

int main() {

    return 0;
}
