#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int N = 32;

// https://leetcode.com/problems/single-number-ii/

int singleNumberII(vector<int>& a) {
    int ans = 0;
    for (int j = 0; j < N; ++j) {
        int bit = 0;
        for (int x : a) {
            if (x & (1 << j)) {
                ++bit;
                bit %= 3;
            }
        }
        if (bit) ans += (1 << j);
    }
    return ans;
}
  
int main() {

    return 0;
}
