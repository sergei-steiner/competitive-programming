#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/min-cost-to-connect-all-points

// couple of heuristics:
// 1) do not sort if possible
// 2) stop early

class Solution {
public:
    int n = 0;
    vector<int> p;
    int find_set(int x) {
        if (x == p[x]) return x;
        return p[x] = find_set(p[x]);
    }
    bool union_sets(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x == y) return false;
        if (rand() & 1) swap(x, y);
        p[x] = y;
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        p.assign(n, 0);
        for (int i = 0; i < n; ++i) p[i] = i;
        int m = 0;
        for (int i = 0; i < n; ++i) {
            m = max(m, abs(points[i][0]) + abs(points[i][1]));
        }
        m = 2 * m + 1;
        vector<vector<pair<int, int>>> e(m);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                e[d].emplace_back(i, j);
            }
        }
        int ans = 0;
        int num = 0;
        for (int d = 0; d < m; ++d) {
        for (auto [i, j] : e[d]) {
            if (union_sets(i, j)) {
                ans += d;
                ++num;
                if (num == n - 1) return ans;
            }
        }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
