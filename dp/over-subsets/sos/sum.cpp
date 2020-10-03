#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

/*

Given a fixed array A of 2^N integers, we need to calculate
∀x function F(x) = Sum of all A[i] such that x & i = i, i.e., i is a subset of x.

https://codeforces.com/blog/entry/45223

O(3^N) is obvious, but we aim for O(2^N)

*/

vector<int> sos(const vector<int>& a, int n) {
    vector<vector<int>> dp(1 << n, vector<int>(n + 1, 0));
    for (int mask = 0; mask < (1 << n); ++mask) {
        dp[mask][0] = a[mask];
    }
    for (int i = 1; i <= n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (mask & (1 << (i - 1))) {
                dp[mask][i] = dp[mask][i - 1] + dp[mask ^ (1 << (i - 1))][i - 1];
            } else {
                dp[mask][i] = dp[mask][i - 1];
            }
        }
    }
    vector<int> f(1 << n);
    for (int mask = 0; mask < (1 << n); ++mask) f[mask] = dp[mask][n];
    return f;
}


vector<int> sos_memory_efficient(const vector<int>& a, int n) {
    vector<int> f = a;
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (mask & (1 << i)) {
                f[mask] += f[mask ^ (1 << i)];
            }
        }
    }
    return f;
}
   
int main() {
    int n;
    cin >> n;

    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); ++i) {
        cin >> a[i];
    }
    
    for (int x : sos(a, n)) {
        cout << x << " ";
    }
    cout << endl;

    for (int x : sos_memory_efficient(a, n)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
