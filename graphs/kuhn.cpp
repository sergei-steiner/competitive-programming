#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;
 
bool try_kuhn(int v) {
	if (used[v]) {
      return false;
  }
	used[v] = true;
	for (int to : g[v]) {
		if (mt[to] == -1 || try_kuh (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}
 

int main() {
    cin >> n >> k;
    
    g.resize(n);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        int y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
    }
    
    mt.assign (k, -1);
	  for (int v = 0; v < n; ++v) {
		    used.assign(n, false);
		    try_kuhn(v);
	  }
    for (int i = 0; i < k; ++i) {
		    if (mt[i] != -1) {
            cout << mt[i] + 1 << " " << i + 1 << endl;
        }
    }
	
    return 0;
}
