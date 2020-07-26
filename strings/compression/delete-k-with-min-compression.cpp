#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/string-compression-ii

class Solution {
public:
    int cnt_digits(int n) {
        int ans = 0;
        while (n > 0) {
            n /= 10;
            ++ans;
        }
        return ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<int> digits(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            digits[i] = cnt_digits(i);
        }
        int inf = 1000000000;
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, inf));
        for (int j = 0; j <= k; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j > 0) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                int cnt1 = 0;
                int cnt2 = 0;
                for (int l = i; l >= 1; --l) {
                    if (s[l - 1] == s[i - 1]) {
                        ++cnt1;
                    } else {
                        ++cnt2;
                    }
                    if (cnt2 > j) break;
                    dp[i][j] = min(dp[i][j], dp[l - 1][j - cnt2] + digits[cnt1] + 1);
                }
            }
        }
        return dp[n][k];
    }
};
    
int main() {

    return 0;
}
