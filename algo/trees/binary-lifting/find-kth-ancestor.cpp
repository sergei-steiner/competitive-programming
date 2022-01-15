#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/kth-ancestor-of-a-tree-node
// binary lifting per se

class TreeAncestor {
public:
    int h = 0;
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& p) {
        while ((1 << h) < n) ++h;
        dp.assign(h, vector<int> (n, -1));
        for (int i = 0; i < n; ++i) dp[0][i] = p[i];
        for (int j = 1; j < h; ++j) {
            for (int i = 0; i < n; ++i) {
                int prev = dp[j - 1][i];
                if (prev != -1) dp[j][i] = dp[j - 1][prev];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int j = 0; j < h; ++j) {
            if (k & (1 << j)) {
                if (dp[j][node] == -1) return -1;
                node = dp[j][node];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */


int main() {

    return 0;
}
