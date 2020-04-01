#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    long long brute_force(vector<int> a) {
        long long ans = numeric_limits<long long>::min();
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                long long cur = 1;
                for (int k = i; k <= j; ++k) {
                    cur *= a[k];
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
    int maxProduct(vector<int>& b) {
        int n = b.size();
        long long ans = numeric_limits<long long>::min();
        vector<int> a;
        for (int i = 0; i <= n; ++i) {
            if (i == b.size() || b[i] == 0) {                
                if (i < b.size()) ans = max(ans, (long long) 0);
                if (a.size() > 0) ans = max(ans, brute_force(a));
                a.clear();
                continue;
            }
            if (b[i] == 1) {
                ans = max(ans, (long long) 1);
                continue;
            }
            a.push_back(b[i]);
            while (a.size() >= 3 && a[a.size() - 1] == -1 && a[a.size() - 2] == -1 && a[a.size() - 3] == -1 ) {
                a.pop_back();
                a.pop_back();
            }
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
