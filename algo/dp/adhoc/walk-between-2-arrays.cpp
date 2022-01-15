#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/get-the-maximum-score

class Solution {
public:
    int mod = 1000000007;
    int maxSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<long long> dp1(n + 1, 0);
        vector<long long> dp2(m + 1, 0);
        map<int, int> aval;
        map<int, int> bval;
        for (int i = 0; i < n; ++i) {
            aval[a[i]] = i + 1;
        }
        for (int i = 0; i < m; ++i) {
            bval[b[i]] = i + 1;
        }
        vector<pair<int, int>> order;
        for (int i = 0; i < n; ++i) {
            order.emplace_back(a[i], 1);
        }
        for (int i = 0; i < m; ++i) {
            order.emplace_back(b[i], 2);
        }
        sort(begin(order), end(order));
        for (auto [val, num] : order) {
            if (num == 1) {
                int i = aval[val];
                dp1[i] = dp1[i - 1] + a[i - 1];
                if (bval.count(val)) {
                    int j = bval[val];
                    dp1[i] = max(dp1[i], dp2[j - 1] + a[i - 1]);
                }
            }
            if (num == 2) {
                int i = bval[val];
                dp2[i] = dp2[i - 1] + b[i - 1];
                if (aval.count(val)) {
                    int j = aval[val];
                    dp2[i] = max(dp2[i], dp1[j - 1] + b[i - 1]);
                }
            }
        }
        return max(dp1[ n ], dp2[ m ]) % mod;
    }
};
    
int main() {

    return 0;
}
