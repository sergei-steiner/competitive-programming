#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/bitwise-ors-of-subarrays/

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& a) {
        int m = 31;
        int n = a.size();
        vector<vector<int>> go(m, vector<int>(n + 1, n));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (a[i] & (1 << j)) {
                    go[j][i] = i;
                    continue;
                }
                go[j][i] = go[j][i + 1];
            }
        }
        set<int> val;
        for (int i = 0; i < n; ++i) {
            int pos = i;
            int cur = 0;
            while (true) {
                int to = n;
                for (int j = 0; j < m; ++j) {
                    if (cur & (1 << j)) {
                        continue;
                    }
                    to = min(to, go[j][pos]);
                }
                int add = 0;
                for (int j = 0; j < m; ++j) {
                    if (cur & (1 << j)) {
                        continue;
                    }
                    if (to == go[j][pos]) {
                         add += (1 << j);
                    }
                }
                pos = to;
                cur += add;
                if (to == n) break;
                val.insert(cur);

            }
        }
        for (int x : a) {
            if (x == 0) val.insert(0);
        }
        return val.size();
    }
};

int main() {

    return 0;
}
