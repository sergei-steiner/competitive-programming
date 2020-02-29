#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://e-maxx.ru/algo/joseph_problem
O(n)
int joseph (int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i) res = (res + k) % i;
    return res + 1;
}

// k = 2
int joseph2(int n) {
    int deg = 1;
    while (deg * 2 <= n) {
        deg *= 2;
    }        
    return 1 + 2 * (n - deg);
}

int main() {

    return 0;
}
