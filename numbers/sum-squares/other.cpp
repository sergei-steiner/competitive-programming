#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// there is randomized polynomial-time algorithms for computing a single representation in expected running time log^2 (n)
// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem#Algorithms

// https://en.wikipedia.org/wiki/Jacobi%27s_four-square_theorem
long long representations_num(long long n) {
    bool odd = n % 2 == 1;
    long long ans = 8;
    if (odd) ans = 24;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
           int deg = i;
           while (n % i == 0) {
               n /= i;
               deg *= i;
           }
           if (!odd || i != 2) ans *= (deg - 1) / (i - 1);
        }
    }
    if (n > 1) ans *= (n + 1);
    return ans;
}

// https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem#Uniqueness

unordered_set<int> uniq_representation_small = {1, 3, 5, 7, 11, 15, 23};

bool uniq_representation(long long n) {
    if (uniq_representation_small.count(n) == 1) return true;
    while (n % 4 == 0) n /= 4;
    return n == 2 || n == 6 || n == 14;
}
unordered_set<int> four_nonzero_small = {1, 3, 5, 9, 11, 17, 29, 41};

bool four_nonzero_representation(long long n) {
    if (four_nonzero_small.count(n) == 1) return false;
    while (n % 4 == 0) n /= 4;
    return n != 2 && n != 6 && n != 14;
}

long long divisors_4n_plus_k(int n, int k) {
    while (n % 2 == 0) n /= 2;
    
    long long ans = 1;
    vector<int> d;
    for (int i = 2; i * i <= n; ++i) {
       if (n % i == 0) {
           int cnt = 0;
           while (n % i == 0) {
               n /= i;
               ++cnt;
           }
           if (i % 4 == 1) {
               ans *= (cnt + 1);
           } else {
               d.push_back(cnt + 1);
           }
       }
    }
    if (n > 1) {
        if (n % 4 == 1) {
            ans *= 2;
        } else {
            d.push_back(2);
        }
    }
    int m = d.size();
    if (m == 0) {
        return ans * (k == 1);
    }
    vector<int> d0(m, 0);
    vector<int> d1(m, 0);
    
    d0[0] = d[0] / 2;
    d1[0] = d[0] - d[0] / 2;
    
    for (int i = 1; i < m; ++i) {
        d0[i] += d0[i - 1] * (d[i] / 2) + d1[i - 1] * (d[i] - d[i] / 2);
        d1[i] += d0[i - 1] * (d[i] - d[i] / 2) + d1[i - 1] * (d[i] / 2);
    }
    
    return ans * (k == 1 ? d0[m - 1] : d1[m - 1]);
}

long long divisors_4n_plus_1(int n) {
    return divisors_4n_plus_k(n, 1);
}

long long divisors_4n_plus_3(int n) {
    return divisors_4n_plus_k(n, 3);
}

// https://mathoverflow.net/questions/242820/jacobis-theorem-on-sums-of-two-squares-reference-request

long long num_of_two_squares_representations(int n) {
    return 4 * (divisors_4n_plus_1(n) - divisors_4n_plus_3(n));
}

int main() {
    
    int n;
    cin >> n;
    cout << min_sum_of_squares(n) << endl;
    cout << representations_num(n) << endl;
    cout << num_of_two_squares_representations(n) << endl;

    return 0;
}
