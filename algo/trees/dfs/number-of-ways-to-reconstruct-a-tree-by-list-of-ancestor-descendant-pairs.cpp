#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree

// https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/discuss/1012453/Simple-Explanation

class Solution {
public:
    int N = 501;
    vector<vector<int>> adj;
    vector<vector<bool>> connected;
    vector<int> deg;
    int n = 0;
    bool many = false;
    
    vector<bool> used;
    vector<int> ancestors;

    bool dfs(int v) {
        if (used[v]) return true;
        for (auto p : ancestors) {
            if (!connected[p][v]) return false;
        }
        ancestors.push_back(v);
        used[v] = true;
        for (int u : adj[v]) {
            if (deg[u] == deg[v]) many = true;
            if (!dfs(u)) return false;
        }
        ancestors.pop_back();
        return true;
    }

    int checkWays(vector<vector<int>>& pairs) {
        deg.assign(N, 0);
        adj.resize(N);
        connected.assign(N, vector<bool> (N, false));
        unordered_set<int> uniq;
        for (auto v : pairs) {
            int x = v[0];
            int y = v[1];
            ++deg[x];
            ++deg[y];
            connected[x][y] = true;
            connected[y][x] = true;
            adj[x].push_back(y);
            adj[y].push_back(x);
            uniq.insert(x);
            uniq.insert(y);
        }
        int n = uniq.size();
        int root = -1;
        for (int k = 0; k < N; ++k) {
            sort(begin(adj[k]), end(adj[k]), [=](int x, int y) {return deg[x] > deg[y];});
            if (adj[k].size() == n - 1) root = k;
        }
        if (root == -1) return 0;
        used.assign(N, false);
        if (dfs(root)) {
            return many ? 2 : 1;
        }
        return 0;
    }
};
    
int main() {

    return 0;
}
