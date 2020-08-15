#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// note 1: for probabilities it is sometimes helpful to use double instead of int64
// note 2: unordeder_map is faster, but no support for pairs: implement hash function by yourself
map<pair<int, int>, int64> C_dp;
int64 C(int n, int k) {
    if (k < 0) return 0;
    if (k > n) return 0;
    if (n == 0) return 1; // k = 0
    if (C_dp.count({n, k})) return C_dp[{n, k}];
    int64 ans = C(n - 1, k - 1) + C(n - 1, k);
    C_dp[{n, k}] = ans;
    return ans;
}

int64 G(int n) {
    return 1LL << (n * (n - 1) / 2);
}

unordered_map<int, int64> Conn_dp;
int Conn(int n) {
    if (n == 1) return 1;
    if (Conn_dp.count(n)) {
        return Conn_dp[n];
    }
    int64 ans = 0;
    for (int K = 1; K <= n - 1; ++K) {
        ans += K * C(n, K) * Conn(K) * G(n - K);
    }
    ans /= n;
    ans = G(n) - ans;
    Conn_dp[n] = ans;
    return ans;
}
int main() {

    return 0;
}
