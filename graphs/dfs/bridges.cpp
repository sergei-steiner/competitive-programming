#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int n;
vector<vector<int>> g;
vector<bool> used;
int timer;
vector<int> tin;
vector<int> fup;
vector<pair<int, int>> bridges;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) bridges.push_back({v, to});
        }
    }
}

void find_bridges() {
    timer = 0;
    for (int i = 0; i < n; ++i) used[i] = false;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
}


int main() {

    return 0;
}
