#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays

// the catch is all-zeroes array
// so be careful to ensure
// j >= i + 1 && j + 1 < n

class Solution {
public:
    int waysToSplit(vector<int>& a) {
        int n = a.size();
        long long mod = 1000000007;
        long long ans = 0;
        int j1 = 1;
        int long j2 = 1;
        vector<int> prefix = a;
        for (int i = 1; i < n; ++i) {
            prefix[i] += prefix[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            if (j1 < i + 1) j1 = i + 1;
            while (j1 + 1 < n && prefix[j1] - prefix[i] < prefix[i]) ++j1;
            if (j2 < j1) j2 = j1;
            while (j2 + 1 < n && prefix[j2] - prefix[i] <= prefix[n - 1] - prefix[j2]) ++j2;
            ans += j2 - j1;
        }
        return ans % mod;
    }
};
    
int main() {

    return 0;
}
