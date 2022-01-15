#include <bits/stdc++.h>


#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int inf = -1000000000;

int n;
vector<pair<int, int>> t;

pair<int, int> combine (pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    return mp(a.first, a.second + b.second);
}

void build(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = mp(a[tl], 1);
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    t[v] = combine(t[2 * v], t[2 * v + 1]);
}

void build(const vector<int>& a) {
    build(a, 1, 0, n - 1);
}

pair<int, int> get_max(int v, int tl, int tr, int l, int r) {
    if (l > r) return mp(-inf, 0);
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return combine(get_max(2 * v, tl, tm, l, min(r, tm)),
                   get_max(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

pair<int, int> get_max(int l, int r) {
    return get_max(1, 0, n - 1, l, r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = mp(new_val, 1);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(2 * v, tl, tm, pos, new_val);
    } else {
        update(2 * v + 1, tm + 1, tr, pos, new_val);
    }
    t[v] = combine(t[2 * v], t[2 * v + 1]);
}

void update(int pos, int new_val) {
    update(1, 0, n - 1, pos, new_val);
}

int main() {
    n = 100000;
    t.resize(4 * n + 1);
    return 0;
}
