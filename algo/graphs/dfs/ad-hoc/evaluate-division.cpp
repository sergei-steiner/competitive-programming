#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    unordered_map<string, unordered_map<string, double>> g;
    unordered_map<string, double> dist;
    void dfs(string u, double val) {
        dist[u] = val;
        for (auto [v, d] : g[u]) {
            if (dist.count(v) == 0) {
                dfs(v, val * d);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double x = values[i];
            g[u][v] = x;
            g[v][u] = 1.0 / x; 
        }
        vector<double> ans;
        for (auto q : queries) {
            if (g.count(q[0]) + g.count(q[1]) != 2) {
                ans.push_back(-1);
                continue;
            }
            dist.clear();
            dfs(q[0], 1.0);
            if (dist.count(q[1])) {
                ans.push_back(dist[q[1]]);    
            } else {
                ans.push_back(-1);
            }
                        
        }
        return ans ;
    }
};
    
int main() {

    return 0;
}
