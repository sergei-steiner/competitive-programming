// http://e-maxx.ru/algo/primitive_root

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int64 powmod(int64 a, int64 n, int64 mod) {
    if (n == 0) return 1 % mod;
    if (n % 2 == 1) return a * powmod(a, n - 1, mod) % mod;
    int64 x = powmod(a, n / 2, mod);
    return x * x % mod;
}

// http://e-maxx.ru/algo/euler_function

int64 phi(int64 n) {
    int64 result = n;
    for (int64 i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

vector<int64> prime_factors(int64 n) {
    vector<int64> factors;
    for (int64 i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            factors.push_back(i);
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int64 gcd(int64 a, int64 b) {
    return b ? gcd(b, a % b) : a;
}

int64 primitive_root(int64 n) {
    int64 phi_n = phi(n);
    vector<int64> factors = prime_factors(phi_n);
    for (int64 i = 1; i <= n; ++i) {
       if (gcd(i, n) != 1) continue;
       bool ok = true;
       for (auto p : factors) {
           if (powmod(i, phi_n / p, n) == 1)  {
               ok = false;
               break;
           }
       } 
       if (ok) return i;
    }

    return -1;
}
    
int main() {
    int64 n;
    cin >> n;

    cout << primitive_root (n) << endl;

    return 0;
}
