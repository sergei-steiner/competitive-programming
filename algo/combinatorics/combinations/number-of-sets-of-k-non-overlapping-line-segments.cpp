#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments
// https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/discuss/898830/Python-O(N)-Solution-with-Prove

/* 

key ideas:

1) k segments = 2 * k points

2) to account for share endpoints, we can just add k - 1 to n

*/

class Solution {
public:
    long long mod = 1000000007;
    
    long long powmod(long long a, long long n) {
        if (n == 0) return 1;
        if (n % 2 == 1) return a * powmod(a,  n - 1) % mod;
        long long x = powmod(a, n / 2);
        return x * x % mod;
    }
    long long inv(long long n) {
        return powmod(n, mod - 2);
    }
    long long f(int n) {
        long long ans = 1;
        for (long long i = 1; i <= n; ++i) {
            ans = (ans * i) % mod;
        }
        return ans;
    }
    long long c(long long n, long long k) {
        if (k < 0 || k > n || n < 0) return 0;
        return f(n) * inv(f(k) * f (n - k) % mod) % mod;
    }
    int numberOfSets(int n, int k) {
        return c(n + k - 1, 2 * k);
    }
};

int main() {

    return 0;
}
