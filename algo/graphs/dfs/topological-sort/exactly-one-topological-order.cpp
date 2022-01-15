#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/sequence-reconstruction

class Solution {
public:
    int n = 0;
    vector<vector<int>> g;
    vector<int> color;
    vector<int> order;
    bool has_cycle(int v) {
        color[v] = 1;
        for (auto to : g[v]) {
            if (color[to] == 0) {
                if (has_cycle(to)) {
                    return true;
                }
            } else if (color[to] == 1) {
                return true;
            }
        }
        order.push_back(v + 1);
        color[v] = 2;
        return false;
    }
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        n = org.size();
        g.resize(n);
        set<pair<int, int>> edges;
        set<int> v;
        for (auto& seq : seqs) {
            for (int x : seq) {
                if (x > n) return false;
                if (x <= 0) return false;
                v.emplace(x);
            }
            for (int i = 1; i < seq.size(); ++i) {
                int from = seq[i - 1] - 1;
                int to = seq[i] - 1;
                g[from].push_back(to);
                edges.emplace(from, to);
            }
        }
        color.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                if (has_cycle(i)) {
                    return false;
                }
            }
        }
        reverse(begin(order), end(order));
        if (order != org) return false;
        for (int i = 1; i < n; ++i) {
            int from = order[i - 1] - 1;
            int to = order[i] - 1;
            if (edges.count({from, to})) continue;
            return false;
        }
        if (v.size() != n) return false;
        for (int i = 1; i <= n; ++i) {
            if (v.count(i)) continue;
            return false;
        }
        return true;
    }
};
    
int main() {

    return 0;
}
