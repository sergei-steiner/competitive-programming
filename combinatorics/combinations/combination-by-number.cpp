#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

using int64 = long long;

map<pair<int, int>, int64> C_dp;
int64 C(int n, int k) {
    if (k < 0) return 0;
    if (k > n) return 0;
    if (n == 0) return 1; // k = 0
    if (C_dp.count({n, k})) return C_dp[{n, k}];
    int64 ans = C(n - 1, k - 1) + C(n - 1, k);
    C_dp[{n, k}] = ans;
    return ans;
}

// 1-indexed number
vector<int> get_combination_by_number(int n, int k, int m) {
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (k == 0) break;
        if (m <= C(n - i - 1, k - 1)) {
            ans.push_back(i);
            --k;
        } else {
            m -= C(n - i - 1, k - 1);
        }
    }
    return ans;
}

// tested on
// https://leetcode.com/problems/kth-smallest-instructions

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int n = destination[0];
        int m = destination[1];
        vector<int> combination = get_combination_by_number(n + m, m, k);
        string ans;
        int j = 0;
        for (int i = 0; i < n + m; ++i) {
            if (j < m && combination[j] == i) {
                ++j;
                ans.push_back('H');
            } else {
                ans.push_back('V');
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
