

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

int countSquares(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 0) continue;
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += dp[i][j] ;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> a(n, vector<int> (m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    
    cout << countSquares(a) << endl;
    
    return 0;
}
