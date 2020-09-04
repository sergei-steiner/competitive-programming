#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations

class Solution {
public:
    int minimumMoves(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int inf = 1000000000;
        vector<vector<int>> dp1(n, vector<int> (m, inf));
        vector<vector<int>> dp2(n, vector<int> (m, inf));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) {
                    dp1[0][0] = 0;
                    if (n >= 2 && a[1][0] == 0 && a[1][1] == 0) dp2[0][0] = 1;
                    continue;
                }
                if (a[i][j] == 0 && j + 1 < m && a[i][j + 1] == 0) {
                    if (i > 0) dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] + 1);
                    if (j > 0) dp1[i][j] = min(dp1[i][j], dp1[i][j - 1] + 1);
                }
                if (a[i][j] == 0 && i + 1 < n && a[i + 1][j] == 0) {
                    if (i > 0) dp2[i][j] = min(dp2[i][j], dp2[i - 1][j] + 1);
                    if (j > 0) dp2[i][j] = min(dp2[i][j], dp2[i][j - 1] + 1);
                }
                if (a[i][j] == 0 && j + 1 < m && a[i][j + 1] == 0 && i + 1 < n && a[i + 1][j] == 0 && a[i + 1][j + 1] == 0) {
                    // the only interesting trick!
                    // we don't have ordering here, but DP still works this way -- just try both options
                    dp1[i][j] = min(dp1[i][j], dp2[i][j] + 1);
                    dp2[i][j] = min(dp2[i][j], dp1[i][j] + 1);
                }
            }
        }
        int ans = dp1[n - 1][m - 2];
        if (ans > inf / 2) return -1;
        return ans;
    }
};

int main() {

    return 0;
}
