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
set<int> cutpoints;

void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (int to : g[v]) {
        if (to == p) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1) cutpoints.insert(v);
            ++children;
        }
    }
    if (p == -1 && children > 1) cutpoints.insert(v);
}

void find_cutpoints() {
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
