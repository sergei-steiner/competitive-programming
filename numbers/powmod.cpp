#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

consexpr int64 mod = 1000000007;

int64 powmod(int64 a, int64 n, int64 p = mod) {
    if (n == 0) return 1 % p;
    if (n % 2 == 1) return a * powmod(a, n - 1, p) % p;
    int64 x = powmod(a, n / 2, p);
    return x * x % p;
}

int main() {
    int64 a;
    int64 n;
    int64 p;
    cout << powmod(a, n, p) << endl;
    return 0;
}
