#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// http://e-maxx.ru/algo/floyd_warshall_algorithm

const int inf = 1000000000;

class Floyd {

  vector<vector<int>> d;
  vector<vector<int>> p;
  int n = 0;

public:
  Floyd(const vector<vector<int>>& a) {
      d = a;
      p.assign(n, vector<int>(n, -1));
      n = a.size();
      for (int k = 0; k < n; ++k) {
          for (int i = 0; i < n; ++i) {
              for (int j = 0; j < n; ++j) {
                   if (d[i][j] > d[i][k] + d[k][j]) {
                       d[i][j] = d[i][k] + d[k][j];
                       p[i][j] = k;
                   } 
              }
          }
      }
  }

  vector<int> path(int i, int j) {
      if (d[i][j] == inf) return {};
      if (i == j) return {};
      if (p[i][j] == -1) return {j};
      vector<int> ans;
      for (int v : path(i, p[i][j])) {
          ans.push_back(v);
      }
      for (int v : path(p[i][j], j)) {
          ans.push_back(v);
      }
      return ans;
  }
};
 
int main() {

    return 0;
}
