// https://atcoder.jp/contests/abc235/tasks/abc235_f

/*

ideas:

- dp both counts and sums
- do DP on numbers LESS than n, handle equality separately
- do from highest digits to lowest ones
- do for all possible digit masks
*/

#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

int64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(0);


    string s;
    cin >> s;
    int m;
    cin >> m;
    int mask = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        mask |= (1 << x);
    }

    int64 prefix = 0;
    int prefix_mask = 0;

    // start from the first 0 digits
    vector<int64> dpc(1 << 10);
    vector<int64> dps(1 << 10);

    for (int i = 0; i < s.size(); ++i) {

       vector<int64> new_dpc(1 << 10);
       vector<int64> new_dps(1 << 10);

       // non-empty prefix
       for (int m = 1; m < (1 << 10); ++m) {
           for (int d = 0; d < 10; ++d) {
               // forward DP
               new_dpc[m | (1 << d)] += dpc[m];
               new_dps[m | (1 << d)] += dps[m] * 10 + dpc[m] * d;
           }
       }

       // empty prefix only makes sense after the first digit
       if (i) {
           for (int d = 1; d < 10; ++d) {
               new_dpc[(1 << d)] += 1;
               new_dps[(1 << d)] += d;
           }
       }

       // handle borderline
       // zero is impossible in the beginning
       int from = 0;
       if (!i) from = 1;
       for (int d = from; d < s[i] - '0'; ++d) {
           new_dpc[prefix_mask | (1 << d)] += 1;
           new_dps[prefix_mask | (1 << d)] += prefix * 10 + d;
       }

       prefix = (10 * prefix + (s[i] - '0')) % mod;
       prefix_mask |= (1 << (s[i] - '0'));

       // handle mod only here
       for (int m = 0; m < (1 << 10); ++m) {
           dpc[m] = new_dpc[m] % mod;
           dps[m] = new_dps[m] % mod;
       }
    }

    int64 ans = 0;
    for (int m = 0; m < (1 << 10); ++m) {
        if ((m & mask) == mask) {
           ans += dps[m];
        }
    }

    if ((prefix_mask & mask) == mask) {
       ans += prefix;
    }

    ans %= mod;
    cout << ans << endl;

    return 0;
}