#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

https://leetcode.com/problems/longest-string-chain

bool add_one_symbol_diff(const string& t, const string& s) {
    int n = s.size();
    int m = t.size();
    if (n + 1 != m) return false;
    int l = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            l = i;
            break;
        }
    }
    int r =  n;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != t[i + 1]) {
            r = n - i - 1;
            break;
        }
    }
    return l + r >= n;
}
    
int main() {

    return 0;
}
