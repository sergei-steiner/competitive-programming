// https://codeforces.com/problemset/problem/1325/D

// Idea: https://codeforces.com/blog/entry/84150

#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int main() {
    int64 u;
    cin >> u;
    int64 v;
    cin >> v;

    if (u > v || u % 2 != v % 2) {
        cout << -1 << endl;
        return 0;
    }

    if (u == 0 && v == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (u == v) {
        cout << 1 << endl;
        cout << u << endl;
        return 0;
    }

    // try for 2

    int64 x = (v + u) / 2; // a|b
    int64 y = (v - u) / 2; // a&b

    // if fits, we can assume a = x, b = y
    if ((x ^ y) == u) { // x + y ==v for sure
        cout << 2 << endl;
        cout << x << " " << y << endl;
        return 0;
    }

    // 3 is always there
    cout << 3 << endl;
    cout << u << " " << (v - u) / 2 << " " << (v - u) / 2 << endl;


    return 0;
}
