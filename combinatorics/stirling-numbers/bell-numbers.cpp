  
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
   if (S_dp.count(n, k)) {
       return S_dp[{n, k}];
   }
   int ans = S(n - 1, k - 1) + k * S(n - 1, k);
   S_dp[{n, k}] = ans;
}

// https://en.wikipedia.org/wiki/Bell_number
// surprisingy this O(n^2) algo is asymptotically close to the best available
// http://fredrikj.net/blog/2015/08/computing-bell-numbers
// quote "the best algorithms available compute B(n) in time n^{2 + o(1)}..."

int bell(int n) {
    int ans = 0;
    for (int k = 0; k <= n; ++k) ans += S(n, k);
    return ans;
}
    
int main() {
    
    int n;
    cin >> n;
    cout << bell(n) << endl;

    return 0;
}
