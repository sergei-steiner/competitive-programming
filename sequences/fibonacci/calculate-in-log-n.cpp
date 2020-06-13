    
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
                 c[i][j] += (long long)a[i][k] * b[k][j] % MODULO;
                 c[i][j] %= MODULO;
            }
        }
    }
    return c;
}

Matrix powmod(const Matrix& a, int n) {
    if (n == 0) {
        Matrix E(a.size(), vector<int>(a.size(), 0));
        for (int i = 0; i < a.size(); ++i) E[i][i] = 1;
        return E;
    }
    if (n % 2 == 1) return mulmod(a, powmod(a, n - 1));
    auto M = powmod(a, n / 2);
    return mulmod(M, M);
}

int fib(int n) {
     Matrix E(2, vector<int>(2, 0));
     E[0] = {0, 1};
     E[1] = {1, 1};
     Matrix M = powmod(E, n);
     return (M[0][0] + M[0][1]) % MODULO;
}
    
int main() {
    int n;
    cin >> n;
    cout << fib(n) << endl;

    return 0;
}
