#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

map<pair<int, int>, int> s_dp;
int s(int n, int k) {
   if (n == 0 && k == 0) return 1;
   if (n == 0) return 0;
   if (k == 0) return 0;
   if (k > n) return 0;
   if (s_dp.count({n, k})) {
       return s_dp[{n, k}];
   }
   int ans = s(n - 1, k - 1) + (n - 1) * s(n - 1, k);
   s_dp[{n, k}] = ans;
}
    
int main() {

    return 0;
}
