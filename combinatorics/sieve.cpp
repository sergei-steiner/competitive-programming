#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
	    if (prime[i]) {
   		    for (int j = i * i; j <= n; j += i) prime[j] = false;
	    }
    }
    return prime;
}

int main() {
    int n;
    cin >> n;
    
    
    auto prime = sieve(n);
    for (int i = 0; i <= n; ++i) {
        if (prime[i]) {
             cout << i << endl;
        }
    }
    
    return 0;
}
