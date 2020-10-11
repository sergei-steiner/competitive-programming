#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums

// I misread the problem, coming up with matrix with possibly negative entries
// firstly, this is problem is still somehow interesting
// secondly, it looks like that you can do some trickery after solving this one, to get the current one

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // "find any matrix"
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<long long>> ans(n, vector<long long>(m, 0));
        for (int i = 0; i < n; ++i) {
            ans[i][0] = rowSum[i];
        }
        for (int j = 0; j < m; ++j) {
            ans[0][j] = colSum[j];
        }
        long long firstRowSum = 0;
        for (int j = 1; j < m; ++j) {
            firstRowSum += colSum[j];
        }
        ans[0][0] = rowSum[0] - firstRowSum;
        
        // swap until a[0][0] -- the only negative one -- becomes >= 0
        while (ans[0][0] < 0) {
            int i = 0;
            for ( ; i < n; ++i) {
                if (ans[i][0] > 0) break;
            }
            int j = 0;
            for ( ; j < m; ++j) {
                if (ans[0][j] > 0) break;
            }
            int delta = min(-ans[0][0], min(ans[i][0], ans[0][j]));
            ans[0][0] += delta;
            ans[i][0] -= delta;
            ans[0][j] -= delta;
            ans[i][j] += delta;
        }
        vector<vector<int>> a(n, vector<int> (m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = ans[i][j];
            }
        }
        return a;
    }
};
    
int main() {

    return 0;
}
