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
        double middle = (minVal + maxVal) / 2;
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

int main() {

    return 0;
}
