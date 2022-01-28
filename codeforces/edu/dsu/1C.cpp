#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

struct DSU {
    int n = 0;
    vector<vector<int>> lst;
    vector<int> p;
    vector<int> val;
    vector<int> group_val;

    DSU(int n) {
        this->n = n;
        lst.resize(n);
        p.resize(n);
        val.assign(n, 0);
        group_val.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            lst[i].push_back(i);
            p[i] = i;
        }
    }

    int FindSet(int x) {
        return p[x];
    }

    void UnionSets(int x, int y) {
        x = FindSet(x);
        y = FindSet(y);
        if (x == y) return;
        if (lst[x].size() < lst[y].size()) {
            swap(x, y);
        }
        for (int i : lst[y]) {
            p[i] = x;
            val[i] += group_val[y] - group_val[x];
            lst[x].push_back(i);
        }
        lst[y].clear();
    }

    int Get(int x) {
        return val[x] + group_val[FindSet(x)];
    }

    void Add(int x, int add) {
        group_val[FindSet(x)] += add;
    }
};

int main() {
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int q;
    cin >> q;

    DSU dsu(n);

    for (int j = 0; j < q; ++j) {
        string s;
        cin >> s;
        if (s == "add") {
            int x, add;
            cin >> x >> add;
            --x;
            dsu.Add(x, add);
        } else if (s == "join") {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            dsu.UnionSets(x, y);
        } else {
            int x;
            cin >> x;
            --x;
            cout << dsu.Get(x) << endl;
        }
    }

    return 0;
}