#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int64 gcd(int64 a, int64 b) {
    return b ? gcd(b, a % b) : a;
}

int64 mulmod(int64 a, int64 b, int64 p) {
    if (b == 0) return 0;
    if (b % 2 == 1) return (a + mulmod(a, b - 1, p)) % p;
    int64 x = mulmod(a, b / 2, p);
    return 2 * x % p;
}

int64 powmod(int64 a, int64 n, int64 p) {
    if (n == 0) return 1 % p;
    if (n % 2 == 1) return mulmod(a, powmod(a, n - 1, p), p);
    int64 x = powmod(a, n / 2, p);
    return mulmod(x, x, p);
}

bool miller_rabin(int64 n, int64 b) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    b %= n;
    if (b < 2) b = 2;
    if (gcd(n, b) != 1) return false;
    int64 p = 0, q = n - 1;
    while (q % 2 == 0) {
        q /= 2;
        ++p;
    }
    int64 rem = powmod(b, q, n);
    if (rem == 1 || rem == n - 1) return true;
    for (int i = 1; i < p; ++i) {
        rem = mulmod(rem, rem, n);
        if (rem == n - 1) return true;
    }
    return false;
}

int64 rand_int64() {
    int64 m = 1000000000;
    int64 x = rand() % m;
    int64 y = rand() % m;
    return x * m + y;
}

bool is_prime(int64 n) {
    for (int i = 0; i < 20; ++i) {
        if (!miller_rabin(n, rand_int64() % n)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << is_prime(n) << endl;
    return 0;
}
