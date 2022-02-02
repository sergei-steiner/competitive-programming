#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

struct Segtree {
    vector<int64> t;
    int64 size = 1;

    void init(int n) {
        while (size < n) size *= 2;
        t.assign(2 * size - 1, 0);
    }

    Segtree(int n) {
        init(n);
    }

    void build(const vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                t[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        t[x] = t[2 * x + 1] + t[2 * x + 2];
    }

    Segtree(const vector<int>& a) {
        init(a.size());
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        t[x] = t[2 * x + 1] + t[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int64 sum(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return 0;
        }
        if (l <= lx && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;
        int64 s1 = sum(l, r, 2 * x + 1, lx, m);
        int64 s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    int64 sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Segtree segtree(a);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, v;
            cin >> i >> v;
            segtree.set(i, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << segtree.sum(l, r) << endl;
        }
    }

    return 0;
}