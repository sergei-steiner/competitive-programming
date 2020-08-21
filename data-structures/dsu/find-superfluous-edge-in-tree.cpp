#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int> p;
    int find_set(int v) {
        if (v == p[v]) return v;
        return p[v] = find_set(p[v]);
    }
    void union_sets(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u == v) return;
        if (rand() & 1) {
            swap(u, v);
        }
        p[u] = v;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p.assign(n, 0);
        for (int i = 0; i < n; ++i) p[i] = i;
        for (auto edge : edges) {
            int x = edge[0];
            int y = edge[1];
            --x;
            --y;
            if (find_set(x) == find_set(y)) return edge;
            union_sets(x, y);
        }
        return {};
    }
};
    
int main() {

    return 0;
}
