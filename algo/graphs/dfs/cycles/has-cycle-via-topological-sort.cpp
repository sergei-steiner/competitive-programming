#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/course-schedule

class Solution {
public:
    
    vector<int> order;
    vector<bool> used;
    vector<vector<int>> g;
    int n = 0;
    void dfs(int v) {
        used[v] = true;
        for (int to : g[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
        order.push_back(v);
    }
    
    bool canFinish(int k, vector<vector<int>>& a) {
        n = k;
        used.assign(n, false);
        g.resize(n);
        for (auto x : a) {
            g[x[0]].push_back(x[1]);
        }
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            dfs(i);
        }
        reverse(begin(order), end(order));
        vector<int> m(n);
        for (int i = 0; i < n; ++i) m[order[i]] = i;
        for (int i = 0; i < n; ++i) {
            for (int j : g[i]) {
                if (m[i] > m[j]) return false;
            }
        }
        return true;
    }
};
    
int main() {

    return 0;
}
