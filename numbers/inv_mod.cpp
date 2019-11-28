#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<int> inv_all(int m) {
  vector<int> r(m, 0);
  r[1] = 1;
  for (int i = 2; i < m; ++i) r[i] = (m - (m / i) * r[m % i] % m) % m;
  return r;
}

int main() {
    int m;
    cin >> m;
    
    auto inv = inv_all(m);
    for (int i = 1; i < m; ++i) {
        cout << i << " * " << inv[i] << " = 1 mod " << m << endl;
    }
    
    return 0;
}
