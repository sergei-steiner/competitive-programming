#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://neerc.ifmo.ru/wiki/index.php?title=Числа_Эйлера_I_и_II_рода
map<pair<int, int>, int> A_dp;
int A(int n, int m) {
   if (n == 0 && m == 0) return 1;
   if (n == 0) return 0;
   if (m == 0) return 0;
   if (m >= n) return 0;
   if (A_dp.count({n, m})) {
       return A_dp[{n, m}];
   }
   int ans = (n - m) * A(n - 1, m - 1) + (m + 1) * A(n - 1, m);
   A_dp[{n, m}] = ans;
   return ans;
}


int f(int n) {
    int ans = 1;
    for (int i = 1; i <= n; ++i) ans *= i;
    return ans;
}

// probability that sum of n i.i.d. on [0, 1] lies between m - 1 and m 
double prob_sum_between(int n, int m) {
     return 1.* A(n, m) / f(n);
}

int main() {

    return 0;
}
