#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/jump-game-vi

// O(n log k)
// with prority queue (implemented as multiset)

class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int n = a.size();
        multiset<int> b;
        vector<int> dp(n, 0);
        dp[0] = a[0];
        b.insert(a[0]);
        for (int i = 1; i < n; ++i) {
            auto it = b.end();
            --it;
            dp[i] = *it + a[i];
            b.insert(dp[i]);
            if (i - k >= 0) {
                b.erase(b.find((dp[i - k])));
            }
        }
        return dp[n - 1];
    }
};
    
int main() {

    return 0;
}
