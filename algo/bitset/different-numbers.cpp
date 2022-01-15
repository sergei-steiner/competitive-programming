/*

https://youtu.be/jqJ5s077OKo?t=417

You are given a sequence of N ≤ 10^7 numbers, each from interval [0,10^9].
How many different values appear in the sequence?
Don't use set or unordered_set because they quite slow.

*/


#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int N = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    bitset<N> b;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b[x] = true;
    }

    cout << b.count() << endl;

    return 0;
}