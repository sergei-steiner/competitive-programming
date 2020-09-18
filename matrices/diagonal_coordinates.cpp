#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/grid-illumination
// x - y for main, x + y for the other one

class Solution {
public:
    unordered_map<int, set<pair<int, int>>> h, v, d1, d2;
    void switch_off(int x, int y) {
        h[x].erase({x, y});
        v[y].erase({x, y});
        d1[x + y].erase({x, y});
        d2[x - y].erase({x, y});
    }
    vector<int> gridIllumination(int N, vector<vector<int>>& a, vector<vector<int>>& queries) {
        for (auto p : a) {
            int x = p[0];
            int y = p[1];
            h[x].insert({x, y});
            v[y].insert({x, y});
            d1[x + y].insert({x, y});
            d2[x - y].insert({x, y});
        }
        vector<int> ans;
        for (auto q : queries) {
            int x = q[0];
            int y = q[1];
            if (!h[x].empty() || !v[y].empty() || !d1[x + y].empty() || !d2[x - y].empty()) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
            for (int i = x - 1; i <= x + 1; ++i) {
                for (int j = y - 1; j <= y + 1; ++j) {
                    switch_off(i, j);
                }
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
