/*

https://youtu.be/jqJ5s077OKo?t=554

You are given N ≤ 1000 items, each with some weight w_i.
Is there a subset of items with total weight exactly W ≤ 10^6

*/


#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int MAX_W = 1e6 + 1;

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int W;
    cin >> W;

    bitset<MAX_W> can;
    can[0] = true;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        can = can | (can << x);
    }

    if (can[W]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}