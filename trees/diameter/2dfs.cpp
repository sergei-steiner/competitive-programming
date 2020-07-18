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
    vector<int> d1;
    vector<int> d2;
    void dfs(int v, vector<int>& d, int dist = 0) {
        d[v] = dist;
        for (auto to : g[v]) {
            if (d[to] == -1) {
                dfs(to, d, dist + 1);
            }
        }
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
        d1.assign(n, -1);
        dfs(0, d1);
        int x = *max_element(begin(d1), end(d1));
        d2.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            if (d1[i] == x) {
                dfs(i, d2);
                break;
            }
        }
        return *max_element(begin(d2), end(d2));
    }
};
    
int main() {

    return 0;
}
