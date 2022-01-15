#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://neerc.ifmo.ru/wiki/index.php?title=Числа_Эйлера_I_и_II_рода
map<pair<int, int>, int> a_dp;
int a(int n, int m) {
   if (n == 0 && m == 0) return 1;
   if (n == 0) return 0;
   if (m == 0) return 0;
   if (m >= 2 * n - 1) return 0;
   if (a_dp.count({n, m})) {
       return a_dp[{n, m}];
   }
   int ans = (2 * n - m - 1) * a(n - 1, m - 1) + (m + 1) * a(n - 1, m);
   a_dp[{n, m}] = ans;
   return ans;
}
    
int main() {

    return 0;
}
