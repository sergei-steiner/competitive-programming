#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// http://e-maxx.ru/algo/kuhn_matching
// https://codeforces.com/blog/entry/17023

// kuhn + optimization
// probably still O(VE)
// but passes this:
// https://judge.yosupo.jp/problem/bipartitematching
// https://judge.yosupo.jp/submission/13731

int n, k;
vector<vector<int>> g;
vector<int> mt_right;
vector<int> mt_left;
vector<bool> used;
 
bool try_kuhn(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int to : g[v]) {
        if (mt_right[to] == -1 || try_kuhn(mt_right[to])) {
            mt_right[to] = v;
            mt_left[v] = to;
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
        //--x;
        //--y;
        g[x].push_back(y);
    }
    
    mt_left.assign(n, -1);
    mt_right.assign(k, -1);
    used.assign(n, false);
        
    int ans = 0;
    while (true) {
        bool ok = false;
        for (int v = 0; v < n; ++v) {
            if (mt_left[v] == -1 && try_kuhn(v)) {
                ++ans;
                ok = true;
            }
        }    
        if (!ok) break;
    }
    
    cout << ans << endl;
    for (int i = 0; i < k; ++i) {
        if (mt_right[i] != -1) {
            cout << mt_right[i] << " " << i << endl;
        }
    }

    return 0;
}
