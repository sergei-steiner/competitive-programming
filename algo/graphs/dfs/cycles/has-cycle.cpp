include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/course-schedule

class Solution {
public:
    vector<int> color;
    vector<vector<int>> g;
    // is acyclic
    bool dfs(int v) {
        color[v] = 1;
        for (int to : g[v]) {
            if (color[to] == 0) {
                if (!dfs(to)) return false;
            } else if (color[to] == 1) {
                return false;
            }
        }
        color[v] = 2;
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& a) {
        g.resize(n);
        for (auto v : a) {
            g[v[1]].push_back(v[0]);
        }
        
        color.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (color[i] != 0) continue;
            if (!dfs(i)) {
                return false;
            }
        }        
        return true;
    }
};

int main() {

    return 0;
}
