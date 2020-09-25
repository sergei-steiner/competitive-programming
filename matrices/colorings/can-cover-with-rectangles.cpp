#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/strange-printer-ii

class Solution {
public:
    bool isPrintable(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int N = 60;
        int inf = 1000000000;
        vector<int> l(N + 1, inf);
        vector<int> r(N + 1, -1);
        vector<int> d(N + 1, inf);
        vector<int> u(N + 1, -1);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = a[i][j];
                if (l[val] == inf) {
                    ++cnt;
                }
                l[val] = min(l[val], j);
                r[val] = max(r[val], j);
                d[val] = min(d[val], i);
                u[val] = max(u[val], i); 
            }
        }
        for (int step = 0; step < cnt; ++step) {
            bool ok = false;
            for (int val = 1; val <= N; ++val) {
                if (l[val] != inf) {
                    bool flag = true;
                    for (int i = d[val]; i <= u[val]; ++i) {
                        for (int j = l[val]; j <= r[val]; ++j) {
                            if (a[i][j] == 0) continue;
                            if (a[i][j] == val) continue;
                            flag = false;
                            break;
                        }
                        if (!flag) break;
                    }
                    if (flag) {
                        ok = true;
                        for (int i = d[val]; i <= u[val]; ++i) {
                            for (int j = l[val]; j <= r[val]; ++j) {
                                a[i][j] = 0;
                            }
                        }
                        l[val] = inf;
                        break;
                    }
                }
            }
            if (!ok) return false; 
        }
        return true;
    }
};
    
int main() {

    return 0;
}
