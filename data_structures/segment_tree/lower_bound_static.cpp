#include <bits/stdc++.h>


#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

static constexpr int inf = 1000000000;

int n;
vector<vector<int>> t;

void build(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = vector<int>{a[tl]};
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    merge(all(t[2 * v]), all(t[2 * v + 1]), back_inserter(t[v]));
}

void build(const vector<int>& a) {
    build(a, 1, 0, n - 1);
}

int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return inf;
    if (l == tl && tr == r) {
        auto pos = lower_bound(all(t[v]), x);
        if (pos != t[v].end()) return *pos;
        return inf;
    }
    int tm = (tl + tr) / 2;
    return min(query(2 * v, tl, tm, l, min(r, tm), x),
               query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, x));
}

int query(int l, int r, int x) {
    return query(1, 0, n - 1, l, r, x);
}

int main() {
    n = 100000;
    t.resize(4 * n + 1);
    return 0;
}
