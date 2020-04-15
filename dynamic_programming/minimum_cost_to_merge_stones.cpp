#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-cost-to-merge-stones/

class Solution {
public:
    vector<int> a;
    map<tuple<int, int, int>, int> dp;
    int inf = 1000000000;
    int K;
    int solve(int i, int j, int m) {
        if (dp.count({i, j, m})) return dp[{i, j, m}];
        if (i == j) {
            if (m == 1) return 0;
            return inf;
        }
        int ans = inf;
        if (m == 1) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += a[k];
            }
            ans = sum + solve(i, j, K);
        } else {
            for (int k = i; k < j; ++k) {
                ans = min(ans, solve(i, k, 1) + solve(k + 1, j, m - 1));
            }
        } 
        dp[{i, j, m}] = ans;
        return ans;
    }
    
    int mergeStones(vector<int>& A, int k) {
        K = k;
        int n = A.size();
        a = A;
        if (k > 2 && n % (k  -  1) != 1) return -1;
        int ans = solve(0, n - 1, 1);
        return ans;
    }
};
    
int main() {

    return 0;
}
