#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// part of https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

long long maxSum(const vector<int>& a, int k) {
    int n = a.size();
    set<long long> sums;
    sums.insert(0);
    long long sum = 0;
    long long ans = numeric_limits<long long>::min();
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        auto it = sums.lower_bound(sum - k);
        if (it != sums.end()) ans = max(ans, sum - *it);
        sums.insert(sum);
    }
        
    return ans;
}
    
    
int main() {

    return 0;
}
