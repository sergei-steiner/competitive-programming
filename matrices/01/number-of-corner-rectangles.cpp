#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/number-of-corner-rectangles

// O(R^2 C)

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int ans = 0;
        for (int i1 = 0; i1 < n; ++i1) {
            for (int i2 = i1 + 1; i2 < n; ++i2) {
                int cnt = 0;
                for (int j = 0; j < m; ++j) {
                    if (a[i1][j] == 1 && a[i2][j] == 1) {
                        ++cnt;
                    }
                }
                ans += cnt * (cnt - 1) / 2;
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
