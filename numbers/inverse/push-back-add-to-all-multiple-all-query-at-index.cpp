/*

a way to inverse linear functions

*/

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/fancy-sequence

// my initial solution:
class Fancy {
public:
    
    long long mod = 1000000007;
    
    vector<long long> a;
    vector<long long> k;
    vector<long long> b;
    
    long long powmod(long long a, long long n) {
        if (n == 0) return 1;
        if (n % 2 == 1) return a * powmod(a, n - 1) % mod;
        long long x = powmod(a, n / 2);
        return x * x % mod;
    }
    
    long long inv(long long a) {
        return powmod(a, mod - 2);
    }

    Fancy() {
        a.push_back(0);
        k.push_back(1);
        b.push_back(0);
    }
    
    void append(int val) {
        a.push_back(val);
        k.push_back(k.back());
        b.push_back(b.back());
    }
    
    void addAll(int inc) {
        b.back() += inc;
        b.back() %= mod;
    }
    
    void multAll(int m) {
        k.back() *= m;
        k.back() %= mod;
        
        b.back() *= m;
        b.back() %= mod;
    }
    
    int getIndex(int i) {
        if (i + 1 >= a.size()) return -1;
        long long k2 = k.back();
        long long k1 = k[i];
        long long b2 = b.back();
        long long b1 = b[i];        
        long long k21 = k2 * inv(k1) % mod;
        long long b21 = (b2 - (b1 * k21) % mod);
        b21 %= mod;
        b21 += mod;
        b21 %= mod;
        long long ans = (k21 * a[i + 1] + b21) % mod;
        return ans;
    }
};

// O(1) additional space
// according to https://leetcode.com/problems/fancy-sequence/discuss/898861/C%2B%2B-Math-Solution-O(1)-extra-space-and-O(1)-time-for-each

int main() {

    return 0;
}
