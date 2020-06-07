#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int64 gcd(int64 a, int64 b) {
    return b ? gcd(b, a % b) : a;
}

int64 mulmod(int64 a, int64 b, int64 p) {
    if (b == 0) return 0;
    if (b % 2 == 1) return (a + mulmod(a, b - 1, p)) % p;
    int64 x = mulmod(a, b / 2, p);
    return 2 * x % p;
}

int64 pollard_rho(int64 n, int iterations_count = 100000) {
	int64 b0 = rand() % n;
	int64 b1 = b0;
	for (int count = 0; count < iterations_count; ++count) {
		b0 = (mulmod(b0, b0, n) + 1) % n;
		b1 = (mulmod(b1, b1, n) + 1) % n;
		b1 = (mulmod(b1, b1, n) + 1) % n;
		int64 g = gcd(abs(b1 - b0), n);
		if (1 < g && g < n) return g;
	}
	return n;
}

vector<int> factorize(int n) {
    if (n == 1) return {};
    if (is_prime(n)) return {n};
    int g = pollard_rho(n);
    if (g == n) return {n};
    vector<int> ans;
    for (int p : factorize(g)) {
        ans.push_back(p);
    }
    for (int p : factorize(n / g)) {
        ans.push_back(p);
    }
    return ans;
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x;
	cin >> x;
	auto v = factorize(x);
	cout << v.size();
	for (int p : v) {
	    cout << " " << p;
	}
	cout << endl;
    }
    return 0;
}