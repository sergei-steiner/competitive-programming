#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

class Solution {
public:
    vector<vector<int>> g;
    vector<bool> used;
    int n = 0;
    void dfs(int v) {
        used[v] = true;
        for (int to : g[v]) {
            if (!used[to]) {
                dfs(to);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        this->n = n;
        g.resize(n);
        for (auto e : edges) {
            int x = e[0];
            int y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        used.assign(n, false);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                dfs(i);
                ++ans;
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
