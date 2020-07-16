#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-size-subarray-sum-equals-k

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> a;
        int ans = 0;
        a[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (a.count(sum - k)) {
                ans = max(ans, i - a[sum - k]);
            }
            if (a.count(sum) == 0) {
                a[sum] = i;
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
