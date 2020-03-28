#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
int pisano_period_naive(int n) {
    int x = 0;
    int y = 1 % n;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (x == 0) return ans;
        ++ans;
        int z = (x + y) % n;
        x = y;
        y = z;
    }
    return -1;
}

int main() {

    return 0;
}
