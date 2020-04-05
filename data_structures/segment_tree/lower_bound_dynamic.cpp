#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long int64;

using namespace std;

static constexpr int inf = 1000000000;

int n;
vector<int> a;
vector<multiset<int>> t;

void build(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = multiset<int>{a[tl]};
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    t[v].insert(all(t[2 * v]));
    t[v].insert(all(t[2 * v + 1]));
}

void build(const vector<int>& a) {
    build(a, 1, 0, n - 1);
}

int query(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return inf;
    if (l == tl && tr == r) {
        auto pos = t[v].lower_bound(x);
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

void update(int v, int tl, int tr, int pos, int new_val) {
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(2 * v, tl, tm, pos, new_val);
        } else {
            update(2 * v + 1, tm + 1, tr, pos, new_val);
        }
    } else {
        a[pos] = new_val;
    }
}

int main() {
    n = 100000;
    a.resize(n);
    t.resize(4 * n + 1);
    return 0;
}
