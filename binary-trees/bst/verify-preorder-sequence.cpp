  
#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree

// the most direct way
// another approach would be turn into inorder...

class Solution {
public:
    tuple<bool, int, int, int> dfs(vector<int>& p, int from, int limit = numeric_limits<int>::max()) {
        int n = p.size();
        if (from >= n || p[from] > limit) {
            return {true, numeric_limits<int>::max(), numeric_limits<int>::min(), from};
        }
        auto [ok1, l1, r1, from1] = dfs(p, from + 1, p[from]);
        auto [ok2, l2, r2, from2] = dfs(p, from1, limit);
        bool ok = ok1 && ok2 && p[from] > r1 && p[from] < l2;
        int l = min(p[from], min(l1, l2));
        int r = max(p[from], max(r1, r2));
        return {ok, l, r, from2};
    }
    
    bool verifyPreorder(vector<int>& p) {
        
        int n = p.size();
        auto [ok, l, r, from] = dfs(p, 0);
        return ok;
    }
};
    
int main() {

    return 0;
}
