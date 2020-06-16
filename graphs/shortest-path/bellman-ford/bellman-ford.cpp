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
    d[v] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            if (d[e.x] < inf) {
                d[e.y] = min(d[e.y], d[e.x] + e.cost);
            }
        }
    }
    return d;
}

int main() {
   
}
