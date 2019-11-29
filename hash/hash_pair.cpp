#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

namespace std {
  template <>
  struct hash<pair<int, int>>
  {
    size_t operator()(const pair<int, int>& p) const
    {
      return (3 * p.first) ^ p.second;
    }
  };
}

int main() {
    unordered_set<pair<int, int>> a;
    return 0;
}
