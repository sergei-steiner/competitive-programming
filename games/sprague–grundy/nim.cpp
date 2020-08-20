#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

bool canWin(const vector<int>& a) {
    int ans = 0;
    for (auto x : a) ans ^= x;
    return ans != 0;
}

int main() {

    return 0;
}
