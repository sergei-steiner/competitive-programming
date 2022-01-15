#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/largest-divisible-subset

// key takeaways are:
// - try to come up with some natural order, so that you can apply simple dp
// (the order here is natural indeed)
// - we can substitute O(n^2) with o(n sqrt(max_val)) or even lower, 
// if we iterate over divisors each time 
// also good exercise on
// 1) enumerating divisors in O(sqrt(val))
// 2) restoring not only dp value, but the optimal sequence itself

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n = a.size();
        if (n == 0) return {};
        sort(begin(a), end(a));
        unordered_map<int, int> b;
        for (int i = 0; i < n; ++i) {
            b[a[i]] = i;
        }
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j * j <= a[i]; ++j) {
                if (a[i] % j != 0) continue;
                if (j != a[i] && b.count(j) == 1) {
                    int k = b[j];
                    if (dp[k] + 1 > dp[i]) {
                        dp[i] = dp[k] + 1;
                        prev[i] = k;
                    }
                }
                int d = a[i] / j;
                if (d != a[i] && b.count(d) == 1) {
                    int k = b[d];
                    if (dp[k] + 1 > dp[i]) {
                        dp[i] = dp[k] + 1;
                        prev[i] = b[d];
                    }
                }
            }
        }
        int max_val = *max_element(begin(dp), end(dp));
        int cur = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == max_val) {
                cur = i;
                break;
            }
        }
        vector<int> ans;
        while (cur != -1) {
            ans.push_back(a[cur]);
            cur = prev[cur];
        }
        return ans;
    }
};

int main() {

    return 0;
}

