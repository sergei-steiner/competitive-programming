#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-height-trees/

// via diameter

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
    
int main() {

    return 0;
}
