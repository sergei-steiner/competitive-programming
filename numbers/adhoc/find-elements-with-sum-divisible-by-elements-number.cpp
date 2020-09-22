#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
 
// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int x : nums) sum += x;
        sum %= p;
        if (sum == 0) return 0;
        unordered_map<int, int> prev;
        prev[0] = -1;
        int n = nums.size();
        int ans = n;
        long long prefix = 0;
        for (int i = 0; i < n; ++i) {
            prefix += nums[i];
            prefix %= p;
            int target = prefix - sum;
            target %= p;
            target += p;
            target %= p;
            if (prev.count(target)) {
                ans = min(ans, i - prev[target]);
            }
            prev[prefix] = i;
        }
        return (ans >= n ? -1 : ans);
    }
};


int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
         cin >> a[i];
    }
    vector<int> sums(n, -1);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        sum %= n;
        if (sums[sum] >= 0) {
            for (int j = sums[sum]; j <= i; ++j) {
                cout << a[j] << " ";
            }
            cout << endl;
            return 0;
        }
        sums[sum] = i + 1;
    }

    return 0;
}
