#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/as-far-from-land-as-possible

// simple, two tricks:
// 1) start from multiple vertices
// 2) ignore "manhattan distance" part

class Solution {
public:
    int maxDistance(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> d(n, vector<int> (m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) {
                    q.push({i, j});
                    d[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (i + 1 < n && d[i + 1][j] == -1) {
                q.push({i + 1, j});
                d[i + 1][j] = d[i][j] + 1;
            }
            if (i > 0 && d[i - 1][j] == -1) {
                q.push({i - 1, j});
                d[i - 1][j] = d[i][j] + 1;
            }
            
            if (j + 1 < m && d[i][j + 1] == -1) {
                q.push({i, j + 1});
                d[i][j + 1] = d[i][j] + 1;
            }
            if (j > 0 && d[i][j - 1] == -1) {
                q.push({i, j - 1});
                d[i][j - 1] = d[i][j] + 1;
            }
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) continue;
                ans = max(ans, d[i][j]);
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
