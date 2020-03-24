#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int inf = 1000000000;

vector<int> dijkstra_set(int s, const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<int> d(n, inf);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({d[s], s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto [to, len] : g[v]) {
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    return d;
}

struct edge {
    int a, b, cost;
};

vector<int> bellman_ford(int s, int n, const vector<edge>& e) {
   vector<int> d(n, inf);
   int m = e.size();
   d[s] = 0;
   for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < m; ++j) {
         if (d[e[j].a] < inf) {
            d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].cost);
	 }
      }
   }
   return d;
}

vector<vector<int>> johnson(vector<vector<pair<int, int>>> g) {
    int n = g.size();
    vector<edge> e;
    for (int i = 0; i < g.size(); ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            edge x;
            x.a = i;
            x.b = g[i][j].first;
            x.cost = g[i][j].second;
            e.push_back(x);
        }
    }
    for (int i = 0; i < n; ++i) {
        edge x;
        x.a = n;
        x.b = i;
        x.cost = 0;
        e.push_back(x);
    }
    vector<int> phi = bellman_ford(n, n + 1, e);
    for (int i = 0; i < g[i]; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            g[i][j].second += phi[i] - phi[g[i][j].first];
	}
    }
    vector<vector<int>> d(n);
    for (int i = 0; i < n; ++i) {
        d[i] = dijkstra_set(i, g);
        for (int j = 0; j < n; ++j) {
	    d[i][j] += phi[j] - phi[i];
	}
    }
    return d; 
}

int main() {

    return 0;
}
