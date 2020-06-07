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

int64 powmod(int64 a, int64 n, int64 p) {
    if (n == 0) return 1 % p;
    if (n % 2 == 1) return a * powmod(a, n - 1, p) % p;
    int64 x = powmod(a, n / 2, p);
    return x * x % p;
}

int64 mulmod(int64 a, int64 b, int64 p) {
    if (b == 0) return 0;
    if (b % 2 == 1) return (a + mulmod(a, b - 1, p)) % p;
    int64 x = mulmod(a, b / 2, p);
    return 2 * x % p;
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

bool is_prime(int64 n) {
    for (int i = 0; i < 10; ++i) {
        if (!miller_rabin(n, rand() % n)) {
            return false;
        }
    }
    return true;
}

int64 pollard_rho_iter(int64 n) {
    if (n % 2 == 0) return 2;
    if (n <= 1000) {
        for (int64 i = 2; i * i <= n; ++i) {
           if (n % i == 0) return i;
        }
    }
    int64 b0 = rand() % n;
    int64 b1 = b0;
    int64 d = 1;
    while (d == 1) {
        b0 = (mulmod(b0, b0, n) + 1) % n;
        b1 = (mulmod(b1, b1, n) + 1) % n;
        b1 = (mulmod(b1, b1, n) + 1) % n;
        d = gcd(abs(b1 - b0), n);
    }
    if (d == n) return -1;
    return d;
}

int64 pollard_rho(int64 n) {
    while (true) {
        int64 ans = pollard_rho_iter(n);
        if (ans != -1) return ans;
    }
}

vector<int64> factorize(int64 n) {
    if (n == 1) return {};
    if (is_prime(n)) return {n};
    int64 g = pollard_rho(n);
    if (g == n) return {n};
    vector<int64> ans;
    for (int64 p : factorize(g)) {
        ans.push_back(p);
    }
    for (int64 p : factorize(n / g)) {
        ans.push_back(p);
    }
    return ans;
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int64 x;
        cin >> x;
        auto v = factorize(x);
        cout << v.size();
        sort(begin(v), end(v));
        for (int64 p : v) {
            cout << " " << p;
        }
        cout << endl;
    }
    return 0;
}
