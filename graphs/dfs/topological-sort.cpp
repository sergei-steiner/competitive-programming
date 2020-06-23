#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<int> order;
vector<bool> used;
vector<vector<int>> g;
int n = 0;

void dfs(int v) {
   used[v] = true;
   for (int to : g[v]) {
      if (!used[to]) {
         dfs(to);
      }
   }
   order.push_back(v);
}
    
vector<int> topological_sort() {
    int n = g.size();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    reverse(begin(order), end(order));
    return order;
}
    
int main() {

    return 0;
}
