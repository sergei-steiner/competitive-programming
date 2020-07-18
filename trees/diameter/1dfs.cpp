#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/tree-diameter

class Solution {
public:
    vector<vector<int>> g;
    int n = 0;
    int ans = 0;
    int dfs(int v, int prev = -1) {
        int m1 = 0;
        int m2 = 0;
        for (auto to : g[v]) {
            if (to != prev) {
                int d = 1 + dfs(to, v);
                if (m1 < d) {
                    m2 = m1;
                    m1 = d;
                } else if (m2 < d) {
                    m2 = d;
                }
            }
        }
        m1;
        m2;
        ans = max(ans, m1 + m2);
        return m1;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        n = edges.size() + 1;
        g.resize(n);
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0);
        return ans;
    }
};
    
int main() {

    return 0;
}
