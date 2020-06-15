#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// http://e-maxx.ru/algo/dijkstra_sparse

const int inf = numeric_limits<int>::max(); 

vector<int> dijkstra_set(int s, const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<int> d(n, inf);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert(mp(d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                q.erase(mp(d[to], to));
                d[to] = d[v] + len;
                q.insert(mp(d[to], to));
            }
        }
    }
    return d;
}


vector<int> dijkstra_set(int s, int t, const vector < vector < pair<int, int> > >& g) {
    int n = g.size();
    vector<int> d(n, inf);
    vector<int> p(n, -1);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert(mp(d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                q.erase(mp(d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(mp(d[to], to));
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
