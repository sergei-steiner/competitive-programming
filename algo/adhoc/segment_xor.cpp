#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int xor(int n) {
    int ans = 0;
    for (int i = n - n % 4; i <= n; ++i) ans ^= i;
    return ans;
}

int xor(int l, int r) {
    int ans = xor(r);
    if (l > 0) ans ^= xor(l - 1);
    return ans;
}

    
int main() {

    return 0;
}
