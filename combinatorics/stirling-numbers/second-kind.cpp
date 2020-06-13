#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

map<pair<int, int>, int> S_dp;
int S(int n, int k) {
   if (n == 0) return 0;
   if (k == 0) return 0;
   if (k > n) return 0;
   if (k == n) return 1;
   if (S_dp.count({n, k})) {
       return S_dp[{n, k}];
   }
   int ans = S(n - 1, k - 1) + k * S(n - 1, k);
   S_dp[{n, k}] = ans;
}
    
int main() {

    return 0;
}
