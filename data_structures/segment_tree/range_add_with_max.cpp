#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int n;

struct Node {
    int add = 0;
    int max = 0;
    Node(int _add, int _max)
        : add(_add)
        , max(_max)
    {
    }
};

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

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r) return;
    if (l == tl && r == tr) {
        t[v] += add;
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), add);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
}

void update(int l, int r, int add) {
    update(1, 0, n - 1, l, r, add);
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        return t[v] + get(2 * v, tl, tm, pos);
    } else {
        return t[v] + get(2 * v + 1, tm + 1, tr, pos);
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
