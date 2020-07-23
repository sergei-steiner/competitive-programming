#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
 
// https://leetcode.com/problems/number-of-distinct-islands

class Solution {
public:
    vector<vector<int>> a;
    int n = 0;
    int m = 0;
    int p = 43;
    int q = 31;
    unsigned int sum = 0;
    unsigned int powmod(int a, int n) {
        if (n == 0) return 1;
        if (n % 2 == 1) return a * powmod(a, n - 1);
        auto x = powmod(a, n / 2);
        return x * x;
    }
    void dfs(int x, int y, int x0, int y0) {
        sum += powmod(p, (n + x - x0)) * powmod(q, (m + y - y0));
        cout << x - x0 << " " << y - y0 << endl;
        a[x][y] = 0;
        if (x + 1 < n && a[x + 1][y] == 1) {
            dfs(x + 1, y, x0, y0);
        }
        
        if (x > 0 && a[x - 1][y] == 1) {
            dfs(x - 1, y, x0, y0);
        }
        
        if (y + 1 < m && a[x][y + 1] == 1) {
            dfs(x, y + 1, x0, y0);
        }
        
        if (y > 0 && a[x][y - 1] == 1) {
            dfs(x, y - 1, x0, y0);
        }
        
    }
    int numDistinctIslands(vector<vector<int>>& a) {
        this->a = a;
        n = a.size();
        m = a[0].size();
        unordered_set<int> b;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (this->a[i][j] == 1) {
                    sum = 0;
                    dfs(i, j, i, j);
                    b.insert(sum);
                }
            }
        }
        return b.size();
    }
};
 
int main() {

    return 0;
}
