#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/ugly-number-ii/

int nthUglyNumber(int n) {
    vector<int> a(n, 0);
    a[0] = 1;
    int j2 = 0;
    int j3 = 0;
    int j5 = 0;
    for (int i = 1; i < n; ++i) {
        a[i] = min(2 * a[j2], min(3 * a[j3], 5 * a[j5]));
        if (a[i] == 2 * a[j2]) {
            ++j2;
        }
        if (a[i] == 3 * a[j3]) {
            ++j3;
        }
        if (a[i] ==  5 * a[j5]) {
            ++j5;
        }
    }
    return a[n - 1];
}

int main() {
    return 0;
}
