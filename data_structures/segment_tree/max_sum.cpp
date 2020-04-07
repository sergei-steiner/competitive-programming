#include<bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

struct data {
    int sum = 0;
    int pref = 0;
    int suff = 0;
    int ans = 0;
};

int n;
vector<data> t;

data combine(data l, data r) {
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

data make_data(int val) {
    data res;
    res.sum = val;
    res.pref = max(0, val);
    res.suff = max(0, val);
    res.ans = max(0, val);
    return res;
}

void build(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = make_data(a[tl]);
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

data query(int v, int tl, int tr, int l, int r) {
    if (l == tl && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return query(2 * v, tl, tm, l, r);
    if (l > tm) return query(2 * v + 1, tm + 1, tr, l, r);
    return combine(query(2 * v, tl, tm, l, tm),
                   query(2 * v + 1, tm + 1, tr, tm + 1, r));
}

int query(int l, int r) {
    return query(1, 0, n - 1, l, r).ans;
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_data(new_val);
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
