#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int dummy = numeric_limits<int>::min();

int n;
vector<int> t;

void build(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
}

void build(const vector<int>& a) {
    build(a, 1, 0, n - 1);
}

void push(int v) {
    if (t[v] != dummy) {
        t[2 * v] = t[v];
        t[2 * v + 1] = t[v];
        t[v] = dummy;
    }
}

void update(int v, int tl, int tr, int l, int r, int color) {
    if (l > r) return;
    if (l == tl && tr == r) {
        t[v] = color;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), color);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, color);
    }
}

void update(int l, int r, int color) {
    update(1, 0, n - 1, l, r, color);
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        return get(2 * v, tl, tm, pos);
    } else {
        return get(2 * v + 1, tm + 1, tr, pos);
    }
}

int get(int pos) {
    return get(1, 0, n - 1, pos);
}

int main() {
    n = 100000;
    t.resize(4 * n + 1);
    return 0;
}
