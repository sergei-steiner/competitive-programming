#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/range-addition
class Solution {
public:
    vector<int> getModifiedArray(int n, vector<vector<int>>& a) {
        vector<int> ans(n, 0);
        for (auto v : a) {
            int l = v[0];
            int r = v[1];
            int add = v[2];
            ans[r] += add;
            if (l > 0) ans[l - 1] -= add;
        }
        for (int i = n - 2; i >= 0; --i) {
            ans[i] += ans[i + 1];
        }
        return ans;
    }
};

int main() {

    return 0;
}
