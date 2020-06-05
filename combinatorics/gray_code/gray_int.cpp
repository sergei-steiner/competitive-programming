#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

int gray(int n) {
	return n ^ (n >> 1);
}

int reverse_gray(int g) {
	int n = 0;
	for ( ; g; g >>= 1) n ^= g;
	return n;
}


int main() {
    int n;
    cin >> n;
    
    cout << n << " -> " << gray(n) << " -> " << reverse_gray(gray(n)) << endl;
    
    return 0;
}
