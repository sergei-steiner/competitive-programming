#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://en.wikipedia.org/wiki/Freivalds%27_algorithm

using Matrix = vector<vector<int>>;

vector<int> mul_vec(const Matrix& A, const vector<int>& x) {
   int n = A.size();
   vector<int> ans(n, vector<int>(n, 0));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
          ans[i] += a[i][j] * x[j];
      }
   }
   return ans;
}

boolean test_product(const Matrix& A, const Matrix& B, const Matrix& C, int trials = 30) {
    int n = A.size();
    for (int t = 0; t < trials; ++t) {
        vector<int> x(n, 0);
        for (int i = 0; i < n; ++i) {
            x[i] = rand() & 1;
        }
        if (mul_vec(A, mul_vec(B, x)) == mul_vec(C, x)) return true;
    }
    return true;
}
    
int main() {

    return 0;
}
