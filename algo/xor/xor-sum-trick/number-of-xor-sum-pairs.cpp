// https://atcoder.jp/contests/abc050/tasks/arc066_b

// Idea: https://codeforces.com/blog/entry/84150

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// are there a and b: a|b = x, a&b = y?
bool ok(int x, int y) {
    for (int i = 0; i < 30; ++i) {
        if (x % 2 == 0 && y % 2 == 1) return false;
        x /= 2;
        y /= 2;
    }
    return true;
}

// u and v should be of same oddity
// v >= u
int f_naive(int n) {
    int ans = 0;
    for (int u = 0; u <= n; ++u) {
        for (int v = u; v <= n; v += 2) {
            if (ok(v + u, v - u)) {
                ++ans;
            }
        }
    }
    return ans;
}

// run naive solution 
// search on oeis
// voila: https://oeis.org/A002487
int f_linear(int n) {
    vector<int> a(n + 10, 0);
    a[0] = 1;
    a[1] = 2;
    for (int i = 2; i <= n; ++i) {
        int k = i / 2;
        if (i % 2 == 0) {
            a[2 * k] = 2 * a[k - 1] + a[k];
        } else {
            a[2 * k + 1] = 2 * a[k] + a[k - 1];
        }
    }
    return a[n];
}

// no the formula above could actually make it done
// in O(log n) time with results caching

int mod = 1000000007;

unordered_map<int64, int64> f_cached;

int64 f(int64 n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (f_cached.count(n)) return f_cached[n];
    int64 k = n / 2;
    int64 ans = 0;
    if (n % 2 == 0) {
        ans = 2 *  f(k - 1) + f(k);
    } else {
        ans = 2 * f(k) + f(k - 1);
    }
    return f_cached[n] = ans % mod;
}

int main() {
    int64 n;
    cin >> n;
    cout << f(n) << endl;

    return 0;
}
