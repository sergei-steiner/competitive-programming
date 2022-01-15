#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island

class Solution {
public:
    int n = 0;
    int m = 0;
    
    void dfs(int i, int j, vector<vector<int>>& a) {
        a[i][j] = 0;
        
        if (i > 0 && a[i - 1][j] == 1) dfs(i - 1, j, a);
        if (i + 1 < n && a[i + 1][j] == 1) dfs(i + 1, j, a);
        if (j > 0 && a[i][j - 1] == 1) dfs(i, j - 1, a);
        if (j + 1 < m && a[i][j + 1] == 1) dfs(i, j + 1, a);
    }
    
    bool connected(vector<vector<int>> a) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) {
                    ++cnt;
                    dfs(i, j, a);
                }
            }
        } 
        return cnt == 1;
    }
    int minDays(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        
        
        int ones = 0;
        for (auto& v : a) {
            for (int x : v) {
                ones += x;
            }
        }
        if (ones <= 1) return ones;
        
        
        if (!connected(a)) return 0;
        for (auto& v : a) {
            for (int& x : v) {
                if (x == 1) {
                    x = 0;
                    if (!connected(a)) return 1;
                    x = 1;
                }
            }
        }
        return 2;
        
    }
};
    
int main() {

    return 0;
}
