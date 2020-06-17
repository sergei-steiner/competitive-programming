    
#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// http://e-maxx.ru/algo/ford_bellman

struct edge {
    int x = 0;
    int y = 0;
    int cost = 0;
};

constexpr int inf = 1000000000;

vector<int> negative_cycle(int n, const vector<edge>& edges) {
    vector<int> d(n, 0);
    // or d[s] = 0, others inf, if we want to find negative cycle
    // only reachable from s
    vector<int> p(n, -1);
    int x = -1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (auto e : edges) {
            if (d[e.x] < inf) {
                if (d[e.y] > d[e.x] + e.cost) {
                    d[e.y] = max(-inf, d[e.x] + e.cost);
                    p[e.y] = e.x;
                    x = e.y;
                }
            }
        }
    }
    if (x == -1) return {};
    int y = x;
    for (int i = 0; i < n; ++i) y = p[y];
    vector<int> ans;
    for (int cur = y; ; cur = p[cur]) {
        ans.push_back(cur);
        if (cur == y && ans.size() > 1) break;
    }
    reverse(begin(ans), end(ans));
    return ans;
}

int main() {
   
}
