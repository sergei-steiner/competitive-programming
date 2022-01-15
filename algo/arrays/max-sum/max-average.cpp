#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

double MaxSum(const vector<double>& a, int minLen) {
    double ans = a[0];
    int n = a.size();
    vector<double> prefixSums(n, 0);
    prefixSums[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefixSums[i] = a[i] + prefixSums[i - 1];
    }
    vector<double> minPrefixSums(n, 0);
    minPrefixSums[0] = prefixSums[0];
    for (int i = 1; i < n; ++i) {
        minPrefixSums[i] = min(prefixSums[i], minPrefixSums[i - 1]);
    }
    for (int i = minLen - 1; i < n; ++i) {
        double result = prefixSums[i];
        if (i - minLen > 0) result -= minPrefixSums[i - minLen - 1];
        ans = max(ans, result);
    }
    
    return ans;
}


double MaxAverage(const vector<int>& a, int minLen, int iterations = 100) {
    double left = *min_element(a.begin(), a.end());
    double right = *max_element(a.begin(), a.end());
    for (int iteration = 0; iteration < iterations; ++iteration) {
        double middle = 0.5 * (left + right);
        vector<double> b;
        for (int item : a) {
            b.push_back(item - middle);
            if (MaxSum(b, minLen) > 0) {
                left = middle;
            } else {
                right = middle;
            }
        }
    }
    return left;
}

// https://leetcode.com/problems/maximum-average-subarray-ii

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double l = -10010;
        double r = 10010;
        for (int step = 0; step < 50 ; ++step) {
            double m = (l + r) / 2;
            vector<double> a;
            a.push_back(0);
            for (int x : nums) {
                a.push_back(x - m + a.back());
            }
            double ans = -1e7;
            vector<double> min_val(n + 1, 0);
            for (int i = 1; i <= n; ++i) {
                min_val[i] = min(min_val[i - 1], a[i]);
                if (i >= k) {
                    ans = max(ans, a[i] - min_val[i - k]);
                }
            }
            if (ans > 0) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};


int main() {

    return 0;
}
