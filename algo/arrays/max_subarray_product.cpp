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

class Solution2 {
public:
    long long solve_no_zeros(vector<int> a) {
        if (a.size() == 1) return a[0];
        long long ans = 1;
        for (int x : a) ans *= x;
        if (ans > 0) return ans;
        long long ans1 = ans;
        for (int i = 0; i + 1 < a.size(); ++i) {
            ans1 /= a[i];
            if (ans1 > 0) break;
        }
        long long ans2 = ans;
        for (int i = a.size() - 1; i > 0; --i) {
            ans2 /= a[i];
            if (ans2 > 0) break;
        }
        return max(ans1, ans2);
    }
    int maxProduct(vector<int>& b) {
        int n = b.size();
        long long ans = numeric_limits<long long>::min();
        vector<int> a;
        for (int i = 0; i <= n; ++i) {
            if (i == b.size() || b[i] == 0) {                
                if (i < b.size()) ans = max(ans, (long long) 0);
                if (a.size() > 0) ans = max(ans, solve_no_zeros(a));
                a.clear();
                continue;
            }
            a.push_back(b[i]);
        }
        return ans;
    }
};
    
int main() {

    return 0;
}
