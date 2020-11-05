#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-height-trees/

// via diameter
// O(n)

class Solution {
public:
    vector<vector<int>> g;
    vector<int> p;
    int s = 0;
    int f = 0;
    int maxh = 0;
    void dfs1(int v, int from = -1, int h = 0) {
        if (h > maxh) {
            maxh = h;
            s = v;
        }
        for (auto to : g[v]) {
            if (to != from) {
                dfs1(to, v, h + 1);
            }
        }
    }
    
    void dfs2(int v, int from = -1, int h = 0) {
        if (h > maxh) {
            maxh = h;
            f = v;
        }
        p[v] = from;
        for (auto to : g[v]) {
            if (to != from) {
                dfs2(to, v, h + 1);
            }
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for (auto e : edges) {
            int x = e[0];
            int y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs1(0);
        
        p.assign(n, -1);
        maxh = 0;
        dfs2(s);
        vector<int> path;
        int v = f;
        path.push_back(v);
        while (v != s) {
            
            v = p[v];
            
            path.push_back(v);
        }
        int m = path.size();
        if (m % 2 == 1) {
            return { path[m / 2] };
        }
        return {path[m / 2], path[m / 2 - 1]};
    }
};


// erasing leaves
// O(n)

class Solution2 {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> g(n);
        for (auto e : edges) {
            int x = e[0];
            int y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> leaves;
        vector<int> degree(n, 0);
        for (int i = 0; i < n; ++i) {
            degree[i] = g[i].size();
            if (degree[i] == 1) {
                leaves.push_back(i);
            }
        }
        vector<bool> erased(n, false);
        int left = n - leaves.size();
        if (left == 0) return leaves;
        while (true) {
            vector<int> new_leaves;
            for (auto v : leaves) {
                erased[v] = true;
                for (auto to : g[v]) {
                    if (!erased[to]) {
                        --degree[to];
                        if (degree[to] == 1) {
                            new_leaves.push_back(to);
                        }
                    }
                }
            }
            swap(leaves, new_leaves);
            if (left <= 2) break;
            left -= leaves.size();
        }
        
        return leaves;
    }
};
    
int main() {

    return 0;
}
