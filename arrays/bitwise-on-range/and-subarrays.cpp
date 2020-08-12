#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target

class Solution {
public:
    int closestToTarget(vector<int>& a, int target) {
        int m = 31;
        int n = a.size();
        vector<vector<int>> go(m, vector<int>(n + 1, n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (a[i] & (1 << j)) {
                } else {
                    go[j][i] = i;
                    continue;
                }
                go[j][i] = go[j][i + 1];
            }
        }
        unordered_set<int> val;
        for (int i = 0; i < n; ++i) {
            int pos = i;
            int cur = a[i];
            val.insert(a[i]);
            while (true) {
                int to = n;
                for (int j = 0; j < m; ++j) {
                    if (cur & (1 << j)) {
                        to = min(to, go[j][pos]);
                    }
                }
                for (int j = 0; j < m; ++j) {
                    if (cur & (1 << j)) {
                        if (to == go[j][pos]) {
                            if (cur & (1 << j)) {
                               cur ^= (1 << j);
                            }
                        }
                    }
                }
            
                pos = to;
                if (to == n) break;
                val.insert(cur);
                
             }
         }
         int ans = numeric_limits<int>::max();
         for (int x : val) {
             ans = min(ans, abs(x - target));
         }
         return ans;
    }

};

int main() {

    return 0;
}
