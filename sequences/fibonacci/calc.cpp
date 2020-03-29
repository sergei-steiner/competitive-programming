    
#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int MODULO = 1000000007; 

using Matrix = vector<vector<int>>;
Matrix mulmod(const Matrix& a, const Matrix& b) {
    int n = a.size();
    Matrix c(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                 c[i][j] += a[i][k] * b[k][j];
                 c[i][j] %= MODULO;
            }
        }
    }
}

Matrix powmod(const Matrix& a, int n) {
    if (n == 0) {
        Matrix E(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) E[i][i] = 1;
        return E;
    }
    if (n % 2 == 1) return mulmod(a, powmod(a, n - 1));
    auto M = powmod(a, n / 2);
    return mulmod(M, M);
}

int fib(int n) {
     Matrix E(2);
     E[0] = {0, 1};
     E[1] = {1, 1};
     Matrix M = powmod(E, n);
     return (M[0][0] + M[0][1]) % MODULO;
}
    
int main() {

    return 0;
}
