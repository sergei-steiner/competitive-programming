#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
string ThueMorse(int n) {
    string ans((1 << n), 'A');
    for (int i = 0; i < (1 << n); ++i) {
        ans[i] = __builtin_popcount(i) % 2 + 'a';
    }
    return ans;
}


// should work for any rolling hash modulo 2^32 or 2^64

// https://codeforces.com/blog/entry/4898

pair<string, string> antihash_test() {
    string s = ThueMorse(14);
    int n = s.size() / 2;
    return {s.substr(0, n), s.substr(n)};
}

unsigned long long _hash(const string& s, int p = 31) {
    int n = s.size();
    unsigned long long ans = 0;
    unsigned long long deg = 1;
    for (int i = 0; i < n; ++i) {
        ans += (s[i] - 'a' + 1) * deg;
        deg *= p;
    }
    return ans;
}

pair<string, string> resilient_antihash_test(int prefix = 1000, int suffix = 1000) {
    auto [first, second] = antihash_test();
	first = string(prefix, 'a')  + first  + string(suffix, 'a');
	second = string(prefix, 'a') + second + string(suffix, 'a');
	return {first, second};
}
	
int main() {
    auto [first, second] = antihash_test();
    cout << "hash( first ) = " << _hash(first) << endl;
    cout << "hash( second ) = " << _hash(second) << endl;
    cout << "first == second is " << boolalpha << ( first == second ) << endl;
    return 0;
}
