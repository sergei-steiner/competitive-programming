#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int64 mulmod(int64 a, int64 b, int64 p) {
    if (b == 0) return 0;
    if (b % 2 == 1) return (a + mulmod(a, b - 1, p)) % p;
    int64 x = mulmod(a, b / 2, p);
    return 2 * x % p;
}

int main() {

    return 0;
}
