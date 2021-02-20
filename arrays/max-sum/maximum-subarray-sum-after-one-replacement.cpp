  
#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-subarray-sum-after-one-operation

// Obvious O(n) space

class Solution {
public:
    int maxSumAfterOperation(vector<int>& a) {
        int n = a.size();
        vector<int> pref = a;
        for (int i = 1; i < n; ++i) {
            pref[i] = max(a[i], pref[i - 1] + a[i]);
        }
        vector<int> suf = a;
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = max(a[i], a[i] + suf[i + 1]);
        }
        int ans = numeric_limits<int>::min();
        for (int i = 0; i < n; ++i) {
            int result = a[i] * a[i];
            if (i > 0) result += max(pref[i - 1], 0);
            if (i + 1 < n) result += max(suf[i + 1], 0);
            ans = max(ans, result); 
        }
        return ans;
    }
};

// Kadane's-like O(1) solution

class Solution2 {
public:
    int maxSumAfterOperation(vector<int>& a) {
        int ans = 0;
        int sum0 = 0;
        int sum1 = 0;
        for (int x : a) {
            sum1 = max(sum1 + x, max(0, sum0) + x * x);
            sum0 = max(x, sum0 + x);
            ans = max(ans, sum1);
        }
        return ans;
    }
};

int main() {

    return 0;
}
