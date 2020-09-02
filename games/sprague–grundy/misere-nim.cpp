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

bool all_ones(const vector<int>& a) {
    for (int x : a) {
        if (x > 1) return false;
    }
    return true;
}

void move(vector<int>& a) {
    int ans = 0;
    for (auto x : a) ans ^= x;
    
    if (ans == 0) {
        for (auto& x : a) {
            if (x != 0) {
               --x;
                return;
            }
        }
    }
    
    int j = -1;
    for (int i = 31; i >= 0; --i) {
        if (ans & (1 << i)) {
            j = i;
            break;
        }
    }
    for (auto& x : a) {
        if (x & (1 << j)) {
            x = x ^ ans;
            if (all_ones(a)) {
               x = 0;
            }
            return;
        }
    }
}

int main() {

    return 0;
}
