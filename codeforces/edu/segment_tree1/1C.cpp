#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

struct Segtree {

    struct node {
        int val = 0;
        int cnt = 0;
    };

    const node ZERO = {INT_MAX, 0};

    node combine(node a, node b) {
        if (a.val < b.val) return a;
        if (a.val > b.val) return b;
        return {a.val, a.cnt + b.cnt};
    }

    vector<node> t;
    int64 size = 1;

    void init(int n) {
        while (size < n) size *= 2;
        t.assign(2 * size - 1, {0, 0});
    }

    Segtree(int n) {
        init(n);
    }

    void build(const vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) {
                t[x] = {a[lx], 1};
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        t[x] = combine(t[2 * x + 1], t[2 * x + 2]);
    }

    Segtree(const vector<int>& a) {
        init(a.size());
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = {v, 1};
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        t[x] = combine(t[2 * x + 1], t[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    node calc(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return ZERO;
        }
        if (l <= lx && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;
        auto res1 = calc(l, r, 2 * x + 1, lx, m);
        auto res2 = calc(l, r, 2 * x + 2, m, rx);
        return combine(res1, res2);
    }

    node calc(int l, int r) {
        return calc(l, r, 0, 0, size);
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
            auto ans = segtree.calc(l, r);
            cout << ans.val << " " << ans.cnt << endl;
        }
    }

    return 0;
}