#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
 
 // https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation
 
 class Solution {
public:
    long long mod = 1000000007;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> a(n, 0);
        for (auto q : requests) {
            int l = q[0];
            int r = q[1];
            ++a[r];
            if (l > 0) --a[l - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            a[i] += a[i + 1];
        }
        sort(begin(a), end(a));
        sort(begin(nums), end(nums));
        long long ans = 0;
        for (int i = 0; i < n; ++i) ans += (long long)a[i] * nums[i];
        ans %= mod;
        return ans;
    }
};
 
int main() {

    return 0;
}
