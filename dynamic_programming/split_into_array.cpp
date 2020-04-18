#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

class Solution {
public:
    int mod = 1000000007;
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (i - j < -1) break;
                long long x = stoll(s.substr(i - j + 1, j));
                if (x > k) continue;
                if (x == 0) continue;
                if (s[i - j + 1] == '0') continue;
                if (i - j == -1) {
                    ++dp[i];
                } else {
                    dp[i] += dp[i - j];
                }
                dp[i] %= mod;
            }
        }
        return dp[n - 1];
    }
};

int main() {
}
