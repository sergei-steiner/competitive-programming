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

int jacobi_symbol_recursive(int64 a, int64 b) {
    if (b == 1) return 1;
    int r = 1;
    if (a < 0) {
        a *= -1;
        if (b % 4 == 3) r *= -1;
    }
    int t = 0;
    while (a % 2 == 0) {
        a /= 2;
        ++t;
    }
    if (t % 2 == 1 && (b % 8 == 3 || b % 8 == 5)) r *= -1;
    if (a % 4 == 3 && b % 4 == 3) r *= -1;
    return r * jacobi_symbol_recursive(b % a, a);
}

int jacobi_symbol(int64 a, int64 b) {
    if (gcd(a, b) != 1) return 0;
    return jacobi_symbol_recursive(a, b);
}

int main() {

    return 0;
}
