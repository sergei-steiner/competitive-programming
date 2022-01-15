// https://atcoder.jp/contests/abc235/tasks/abc235_g

/*

ideas:
 - inclusion-exclusion is rather straightforward, O(n^2)
 - there is no way to compute P(n, k) = C(n, 0) + ... C(n, k) efficiently, but P(n, k) could be computed in O(1) from P(n - 1, k)
 - the key point I missed during the contest: to compute inverse factorials efficiently, inverse only n!, then multiply by n, n-1, n-2, .... in the reverse order

*/

#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

int64 mod = 998244353;

int64 powmod(int64 a, int64 n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return a * powmod(a, n - 1) % mod;
    int64 x = powmod(a, n / 2);
    return x * x % mod;
}

int64 inv(int64 a) {
    return powmod(a, mod - 2);
}

vector<int64> f;
vector<int64> f_inv;


int64 comb(int64 n, int64 k) {
    return f[n] * f_inv[k] % mod * f_inv[n - k] % mod;
}

vector<int64> count(int64 n, int64 k) {
    vector<int64> ans(n + 1, 1);
    if (k == 0) return ans;
    for (int i = 1; i <= n; ++i) {
        if (i <= k) {
            ans[i] = ans[i - 1] * 2 % mod;
            continue;
        }
        ans[i] = 2 * ans[i - 1] - comb(i - 1, 0) - comb(i - 1, k) + comb(i, 0);
        ans[i] %= mod;
        if (ans[i] < 0) ans[i] += mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);


    int64 n, a, b, c;
    cin >> n >> a >> b >> c;


    f.assign(n + 1, 1);
    for (int64 i = 2; i <= n; ++i) {
        f[i] = (f[i - 1] * i) % mod;
    }

    f_inv.assign(n + 1, 1);
    f_inv[n] = inv(f[n]);
    for (int i = n - 1; i >= 1; --i) f_inv[i] = (i + 1) * f_inv[i + 1] % mod;

    vector<int64> A = count(n, a);
    vector<int64> B = count(n, b);
    vector<int64> C = count(n, c);

    int64 ans = 0;
    int64 sgn = 1;
    for (int i = n; i >= 0; --i) {
        int64 add = A[i];
        add *= B[i];
        add %= mod;
        add *= C[i];
        add %= mod;

        add *= comb(n, i);

        ans += add * sgn;
        sgn *= -1;
        ans %= mod;
        ans += mod;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}