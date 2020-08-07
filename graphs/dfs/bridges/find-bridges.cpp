#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    int n;
    vector<vector<int>> g;
    vector<bool> used;
    int timer;
    vector<int> tin;
    vector<int> fup;
    vector<pair<int, int>> bridges;

    void dfs(int v, int p = -1) {
        used[v] = true;
        tin[v] = fup[v] = timer++;
        for (int to : g[v]) {
            if (to == p) continue;
            if (used[to]) {
                fup[v] = min(fup[v], tin[to]);
            } else {
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
                if (fup[to] > tin[v]) bridges.push_back({v, to});
            }
        }
    }

    void find_bridges() {
        timer = 0;    
        
        used.assign(n, false);
        tin.assign(n, -1);
        fup.assign(n, -1);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                dfs(i);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        this->n = n;
        g.resize(n);
        for (auto v : connections) {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        find_bridges();
        vector<vector<int>> ans;
        for (auto [x, y] : bridges) {
            ans.push_back(vector<int>{x, y});
        }
        return ans;
    }
};


int main() {

    return 0;
}
