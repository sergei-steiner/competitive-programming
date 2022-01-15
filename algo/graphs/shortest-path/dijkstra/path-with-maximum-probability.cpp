#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/path-with-maximum-probability

class Solution {
public:
    
    vector<double> dijkstra_set(int s, const vector<vector<pair<int, double>>>& g) {
        int n = g.size();
        vector<double> d(n, 0);
        d[s] = 1;
        set<pair<double, int>> q;
        q.insert({d[s], s});
        while (!q.empty()) {
            int v = (--q.end())->second;
            q.erase(--q.end());
            for (auto [to, len] : g[v]) {
                if (d[v] * len > d[to]) {
                    q.erase({d[to], to});
                    d[to] = d[v] * len;
                    q.insert({d[to], to});
                }
            }
        }
        return d;
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> g(n);
        for (int i = 0; i < edges.size(); ++i) {
            int x = edges[i][0];
            int y = edges[i][1];
            double p = succProb[i];
            g[x].emplace_back(y, p);
            g[y].emplace_back(x, p);
        }
        
        return dijkstra_set(start, g)[end];
    }
};
    
int main() {

    return 0;
}
