#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array

class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        int inf = 1000010000;
        vector<int> ans(n, -1);
        vector<int> left(n + 1, inf);
        left[0] = -inf;
        for (int i = 0; i < n; ++i) {
            int j = upper_bound(begin(left), end(left), a[i]) - left.begin();
            if (left[j - 1] < a[i]) {
                left[j] = a[i];
                ans[i] += j;
            } else {
                ans[i] += j - 1;
            }
        }
        vector<int> right(n + 1, inf);
        right[0] = -inf;
        for (int i = n - 1; i >= 0; --i) {
            int j = upper_bound(begin(right), end(right), a[i]) - right.begin();
            if (right[j - 1] < a[i]) {
                right[j] = a[i];
                if (ans[i]) {
                    ans[i] += j;
                }
            } else {
                if (ans[i]) {
                    ans[i] += j - 1;
                }
            }
        }
        return n - *max_element(begin(ans), end(ans));
    }
};

int main() {

    return 0;
}
