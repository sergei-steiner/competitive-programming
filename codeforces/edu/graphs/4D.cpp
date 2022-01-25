#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int64 n;
        cin >> n;
        int64 nn = n * n;
        int64 m;
        cin >> m;
        vector<int64> cnt(n, 0);
        vector<pair<int, int>> edges;
        vector<unordered_set<int>> ok(n);
        vector<vector<int>> g(n);
        int64 ans = 0;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            int y;
            cin >> y;
            --x;
            --y;
            if (x > y) {
                swap(x, y);
            }
            ++cnt[x];
            ++cnt[y];
            edges.emplace_back(x, y);
            ok[x].emplace(y);
            ok[y].emplace(x);
            g[x].push_back(y);
        }
        for (int64 x : cnt) ans += x * (x - 1);
        unordered_set<int> large;
        for (int i = 0; i < n; ++i) {
             if (cnt[i] * cnt[i] > m) {
                 large.emplace(i);
             }
        }
       for (int x = 0; x < n; ++x) {
             if (cnt[x] * cnt[x] > m) {
                 continue;
             }
             sort(begin(g[x]), end(g[x]));
             for (int j = 0; j < g[x].size(); ++j) {
                 int y = g[x][j];
                 if (large.count(y)) continue;
                 for (int k = j + 1; k < g[x].size(); ++k) {
                      int z = g[x][k];
                      if (large.count(z)) continue;
                      if (ok[y].count(z)) ans -= 6;
                 }
             }
        }
        for (auto e : edges) {
            auto [x, y]  = e;
            int total = large.count(x) + large.count(y) + 1;
            for (auto z : large) {
                 if (x == z || y == z) continue;
                 if (ok[x].count(z) && ok[y].count(z)) {
                     if (total == 1) {
                         ans -= 6;
                     } else if (total == 2) {
                         ans -= 3;
                     } else {
                         ans -= 2;
                     }
                 }

            }
        }
        cout << ans / 2 << endl;
    }

    return 0;
}