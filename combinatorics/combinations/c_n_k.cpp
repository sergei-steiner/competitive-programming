#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// note 1: for probabilities it is sometimes helpful to use double instead of int64
// note 2: unordeder_map is faster, but no support for pairs: implement hash function by yourself
map<pair<int, int>, int64> C_dp;
int64 C(int n, int k) {
    if (k < 0) return 0;
    if (k > n) return 0;
    if (n == 0) return 1; // k = 0
    if (C_dp.count({n, k})) return C_dp[{n, k}];
    int64 ans = C(n - 1, k - 1) + C(n - 1, k);
    C_dp[{n, k}] = ans;
    return ans;
}

// Hypergeometric distribution
// https://en.wikipedia.org/wiki/Hypergeometric_distribution
// N is the population size
// K is the number of success states in the population
// n is the number of draws (i.e. quantity drawn in each trial)
// k is the number of observed successes

double HyperGeom(int k, int n, int K, int N) {
    return 1.0 * C(K, k) * C(N - K, n - k) / C(N, n);
}


// Multinomial distribution
// https://en.wikipedia.org/wiki/Multinomial_theorem

// via C(n, k)
int64 MultiC(int n, const vector<int>& K) {
   int64 ans = 1;
   int sum = 0;
   for (int k : K) {
       sum += k;
       ans *= C(sum, k);
   }
   return ans;
}
    
int main() {
    int n, k;
    cin >> n >> k;
    cout << C(n, k) << endl;

    return 0;
}
