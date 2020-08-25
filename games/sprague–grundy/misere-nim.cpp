#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

bool canWin(const vector<int>& a) {
    bool all_ones = true;
    for (auto x : a) {
        if (x != 1) {
            all_ones = false;
            break;
        }
    }
    
    if (all_ones) {
        return a.size() % 2 == 0;
    }
    
    int ans = 0;
    for (auto x : a) ans ^= x;
    return ans != 0;
}

int main() {

    return 0;
}
