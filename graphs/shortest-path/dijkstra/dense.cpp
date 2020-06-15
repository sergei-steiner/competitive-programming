#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// http://e-maxx.ru/algo/dijkstra

const int inf = numeric_limits<int>::max(); 

vector<int> dijkstra(int s, const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<int> d(n, inf);
    d[s] = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;
            if (v == -1 || d[j] < d[v]) v = j;
        }
        if (d[v] == inf) break;
        used[v] = true;
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
            }
        }
    }
    return d;
}

vector<int> dijkstra(int s, int t, const vector <vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<int> d(n, inf);
    vector<int> p(n, -1);
    d[s] = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
        if (used[j]) continue;
        if (v == -1 || d[j] < d[v]) v = j;
    }
    if (d[v] == inf) break;
    used[v] = true;
    for (auto [to, len] : g[v]) {
        if (d[v] + len < d[to]) {
            d[to] = d[v] + len;
            p[to] = v;
            }
        }
    }
    if (d[t] == inf) return vector<int>();
    vector<int> path;
    for (int cur = t; cur != -1; cur = p[cur]) path.pb(cur);
    reverse(path.begin(), path.end());
    return path;
}

int main() {

    return 0;
}
