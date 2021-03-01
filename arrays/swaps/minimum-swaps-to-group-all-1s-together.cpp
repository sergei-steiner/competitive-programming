#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together

class Solution {
public:
    int minSwaps(vector<int>& a) {
        int n = a.size();
        int k = 0;
        for (int x : a) k += x;
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (i >= k) sum -= a[i - k];
            ans = max(ans, sum);
        }
        ans = k - ans;
        return ans;
    }
};

int main() {

    return 0;
}
