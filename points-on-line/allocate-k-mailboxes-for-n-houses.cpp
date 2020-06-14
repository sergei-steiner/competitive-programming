#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/allocate-mailboxes
// O(n^3 k) dp is rather straightforward
// but we can exploit two pointers method
// to eliminate one dimension
// so it's O(n^2 k) = O(n^3)

class Solution {
public:
    int minDistance(vector<int>& h, int k) {
        int n = h.size();
        sort(begin(h), end(h));
        vector<vector<long long>> f(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                long long sum = 0;
                for (int l = i; l <= j; ++l) {
                    sum += h[l] - h[i];
                }
                f[i][j] = sum;
            }
        }
        long long inf = 1000000000;
        inf *= inf;
        vector<vector<long long>> dp(n, vector<long long> (k + 1, inf));
        for (int i = 0; i < n; ++i) {
            dp[i][1] = 0;
            for (int l = 0; l <= i; ++l) dp[i][1] += (h[i] - h[l]);
        }
        for (int j = 2; j <= k; ++j) {
            for (int i = 0; i < n; ++i) {
                long long sum = 0;
                int pos = i;
                for (int l = i - 1; l >= 0; --l) {
                    while (pos >= l && h[i] - h[pos] < h[pos] - h[l]) {
                        sum += h[i] - h[pos];
                        --pos;
                    }
                    dp[i][j] = min(dp[i][j], dp[l][j - 1] + sum + f[l][pos]);
                }
            }
        }
        long long ans = inf;
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int l = i + 1; l < n; ++l) {
                sum += h[l] - h[i];
            }
            ans = min(ans, dp[i][k] + sum);
        }
        return ans;
    }
};

int main() {

    return 0;
}
