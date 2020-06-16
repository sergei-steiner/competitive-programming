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
 
vector<int> bellman_ford(int n, const vector<edge>& edges, int s) {
    vector<int> d(n, inf);
    d[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            if (d[e.x] < inf) {
                d[e.y] = min(d[e.y], d[e.x] + e.cost);
            }
        }
    }
    return d;
}

vector<int> bellman_ford_refined(int n, const vector<edge>& edges, int s) {
    vector<int> d(n, inf);
    d[s] = 0;
    while (true) {
        bool any = false;
        for (auto e : edges) {
            if (d[e.x] < inf) {
                d[e.y] = min(d[e.y], d[e.x] + e.cost);
                any = true;
            }
        }
        if (!any) break;
    }
    return d;
}

vector<int> bellman_ford_refined(int n, const vector<edge>& edges, int s, int t) {
    vector<int> d(n, inf);
    vector<int> p(n, -1);
    d[s] = 0;
    while (true) {
        bool any = false;
        for (auto e : edges) {
            if (d[e.x] < inf) {
                if (d[e.y] < d[e.x] + e.cost) {
                    d[e.y] = d[e.x] + e.cost;
                    p[e.y] = e.x;
                }
                any = true;
            }
        }
        if (!any) break;
    }
    if (d[t] > inf / 2) return {};
    vector<int> ans;
    for (int cur = t; cur != s; cur = p[cur]) {
        ans.push_back(cur);
    }
    reverse(begin(ans), end(ans));
    return ans;
}


int main() {
   
}
