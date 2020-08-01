#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/digit-count-in-range

class Solution {
public:
    int ans_for_zero_fixed(int n) {
        if (n == 1) return 1;
        return 9 * (n - 1) * pow(10, n - 2);
    }
    int ans_for_zero(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) ans += ans_for_zero_fixed(i);
        return ans;
    }
    int digitsCount(int d, int N) {
        if (N == 0) return d == 0;
        stringstream ss;
        ss << N;
        string s = ss.str();
        reverse(begin(s), end(s));
        int n = s.size();
        vector<int> deg(n, 1);
        for (int i = 1; i < n; ++i) deg[i] = 10 * deg[i - 1];
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int D = s[i - 1] - '0';
            // first digit less than D
            for (int j = 0; j < D; ++j) {
                if (j == d) {
                    int add = deg[i - 1];
                    // first digit trickery
                    if (d == 0 && i == n && n > 1) add = 0;
                    dp[i] += add;
                }
                int add = (i - 1) * deg[i - 1] / 10;
                if (j == 0 && d == 0 && i == n && n > 1) {
                    // zero trickery
                    add = ans_for_zero(i - 1);
                }
                dp[i] += add;
            }
            // first digit equals D
            dp[i] += dp[i - 1];
            if (d == D) {
                string pre = s.substr(0, i - 1);
                reverse(begin(pre), end(pre));
                if (pre.empty()) pre = "0";
                int add = stoi(pre) + 1;
                dp[i] += add;
            }
        }
        return dp[n];
    }
    int digitsCount(int d, int low, int high) {
        return digitsCount(d, high) - digitsCount(d, low - 1);
    }
}; 
 
int main() {

    return 0;
}
