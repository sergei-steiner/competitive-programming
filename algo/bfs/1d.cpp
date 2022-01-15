#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int bfs(const vector<vector<int>>& g) {
   int n = g.size();
   vector<int> d(n, -1);
   queue<int> q;
   q.push(0);
   d[0] = 0;
   while (! q.empty()) {
      int v = q.front();
      q.pop();
      for (int to : g[v]) {
          if (d[to] == -1) {
              d[to] = d[v] + 1;
              q.push(to);
          }
      }
   }
   
   return d[n - 1];
}


    
int main() {

    return 0;
}
