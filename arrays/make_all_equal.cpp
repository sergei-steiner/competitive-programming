#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
 
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 1; i < N; ++i) ans += nums[i] - nums[0];
        return ans;
    }
};

// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

int minMoves2(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;
    sort(begin(a), end(a));
    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        ans += abs(a[i] - a[n - i - 1]);
    }
    return ans;
}
 
int main() {

    return 0;
}
