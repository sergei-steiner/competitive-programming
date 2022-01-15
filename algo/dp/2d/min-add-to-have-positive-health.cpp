#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;


// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int> (m));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int step = 0;
                if (i + 1 < n) step = dp[i + 1][j];
                if (j + 1 < m) step = dp[i][j + 1];
                if (i + 1 < n && j + 1 < m) step = max(dp[i + 1][j], dp[i][j + 1]);
    
                dp[i][j] = dungeon[i][j] + min(0, step);
            }
        }
        return ` max(1 - dp[0][0], 1);
    }
};
    
int main() {

    return 0;
}
