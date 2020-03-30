#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int n;
vector<int> t;

void build(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = (a[tl] ? 0 : 1);
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, 2 * v, tl, tm);
    build(a, 2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
}

void build(const vector<int>& a) {
    build(a, 1, 0, n - 1);
}

int count_zeros(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return count_zeros(2 * v, tl, tm, l, min(r, tm)) +
           count_zeros(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

int count_zeros(int l, int r) {
    return count_zeros(1, 0, n - 1, l, r);
}

int find_kth(int v, int tl, int tr, int k) {
    if (k > t[v]) return -1;
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    if (t[2 * v] >= k) return find_kth(2 * v, tl, tm, k);
    return find_kth(2 * v + 1, tm + 1, tr, k - t[2 * v]);
}

int find_kth(int k) {
    return find_kth(1, 0, n - 1, k);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = (new_val ? 0 : 1);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(2 * v, tl, tm, pos, new_val);
    } else {
        update(2 * v + 1, tm + 1, tr, pos, new_val);
    }
    t[v] = t[2 * v] +  t[2 * v + 1];
}

void update(int pos, int new_val) {
    update(1, 0, n - 1, pos, new_val);
}


int main() {
    n = 100000;
    t.resize(4 * n + 1);
    return 0;
}
