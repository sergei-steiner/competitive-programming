#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/graph-valid-tree

class Solution {
public:
    vector<vector<int>> g;
    vector<bool> used;
    void dfs(int v) {
        used[v] = true;
        for (int to : g[v]) {
            if (!used[to]) dfs(to);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for (auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        used.assign(n, false);
        dfs(0);
        for (int i = 1; i < n; ++i) {
            if (!used[i]) return false;
        }
        return edges.size() == n - 1;
    }
};

int main() {

    return 0;
}
