#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths-ii/
// O(n log n + q log n)
// just use listwise DSU + remember all merges

struct DSU {
    vector<int> p;
    vector<vector<int>> group;
    vector<vector<pair<int, int>>> events;
    
    DSU(int n) {
        p.resize(n);
        group.resize(n);
        events.resize(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            group[i] = {i};
            events[i].emplace_back(0, i);
        }
    }
    
    void UnionSets(int x, int y, int w) {
        x = p[x];
        y = p[y];
        
        
        if (x == y) return;
        if (group[x] > group[y]) {
            swap(x, y);
        }
        for (int v : group[x]) {
            p[v] = y;
            group[y].push_back(v);
            events[v].emplace_back(w, y);
        }
    }
};

class DistanceLimitedPathsExist {
public:
    DSU dsu;
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList)
      : dsu(n)
      {
        sort(begin(edgeList), end(edgeList), [](auto x, auto y) { return x[2] < y[2]; });
        

        for (auto e : edgeList) {
            int x = e[0];
            int y = e[1];
            int w = e[2];
            dsu.UnionSets(x, y, w);
        }
    }
    
    bool query(int p, int q, int limit) {
        int i = lower_bound(dsu.events[p].begin(), dsu.events[p].end(), make_pair(limit, 0)) - dsu.events[p].begin() - 1;
        int j = lower_bound(dsu.events[q].begin(), dsu.events[q].end(), make_pair(limit, 0)) - dsu.events[q].begin() - 1;
        return dsu.events[p][i].second == dsu.events[q][j].second;
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */
    
int main() {

    return 0;
}
