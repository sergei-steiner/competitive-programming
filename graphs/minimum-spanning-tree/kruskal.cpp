#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://neerc.ifmo.ru/wiki/index.php?title=Алгоритм_Краскала
// O(ElogE)

int n;
vector<int> p;

int findset(int v) {
    if (v == p[v]) return v;
    return p[v] = findset(p[v]);
}

void unionsets(int u, int v) {
    u = findset(u);
    v = findset(v);
    if (u == v) return;
    if (rand() & 1) swap(u, v);
    p[u] = v;
 }
 
 int spanning_tree_length(vector<vector<int>> e) {
    int ans = 0;
    p.assign(n, 0);
    for (int i = 0; i < n; ++i) p[i] = i;
    sort(begin(e), end(e), [](auto x, auto y){ return x[2] < y[2]; });
    for (auto edge : e) {
       int x = edge[0];
       int y = edge[1];
       int w = edge[2];
       if (findset(x) == findset(y)) continue;
       ans += w;
       unionsets(x, y);
    }
    return ans;
  }
    
    
int main() {
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> e;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        int y;
        cin >> y;
        int w;
        cin >> w;
        e.push_back({x, y, w});
    }
    cout << spanning_tree_length(e) << endl;
    return 0;
}
