#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

// https://leetcode.com/problems/maximum-number-of-ones/

// max number of ones, so that in any subsquare lXl not more than k ones

class Solution {
public:
    int maximumNumberOfOnes(int n, int m, int l, int k) {
        vector<vector<int>> a(l, vector<int> (l, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ++a[i % l][j % l];
            }
        }
        vector<int> b;
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                b.push_back(a[i][j]);
            }
        }
        sort(begin(b), end(b));
        reverse(begin(b), end(b));
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += b[i];
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
