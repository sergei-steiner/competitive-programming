#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/find-the-shortest-superstring/

class Solution {
public:    
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        if (n == 1) return A[0];
        vector<int> len(n);
        for (int i = 0; i < n; ++i) len[i] = A[i].size();
        vector<vector<int>> d(n, vector<int> (n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                 for (int k = 0; k < A[i].size(); ++k) {
                    string s1 = A[i].substr(k);
                    string s2 = A[j].substr(0, A[i].size() - k);
                    if (s1 == s2) {
                        d[i][j] = A[i].size() - k;
                        break;
                    }
                 }
            }
        }
        int inf = 100000000;
        vector<vector<int>> dp(1 << n, vector<int> (n, inf));
        vector<vector<string>> res(1 << n, vector<string> (n));
        for (int j = 0; j < n; ++j) {
            dp[1 << j][j] = len[j];
            res[1 << j][j] = A[j];
        }
        int ans = inf;
        string result;
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    for (int k = 0; k < n; ++k) {
                        if (i & (1 << k)) {
                            if (j != k) {
                                if (dp[i][j] > dp[i ^ (1 << j)][k] + len[j] - d[k][j]) {
                                    dp[i][j] = dp[i ^ (1 << j)][k] + len[j] - d[k][j];
                                    res[i][j] = res[i ^ (1 << j)][k] + A[j].substr(d[k][j]);
                                    if (ans > dp[i][j] && i == (1 << n) - 1) {
                                        ans = dp[i][j];
                                        result = res[i][j];
                                    }           
                                }
                            }
                        }
                    }   
                }
            }
        }
        return result;
    }
};
    
int main() {

    return 0;
}
