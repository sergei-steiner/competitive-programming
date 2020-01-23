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


// should work for any rolling hash modulo 2^32

pair<string, string> antihash_test() {
    string s = ThueMorse(14);
    int n = s.size() / 2;
    return {s.substr(0, n), s.substr(n)};
}

unsigned int _hash(const string& s, int p = 31) {
    int n = s.size();
    unsigned int ans = 0;
    unsigned int deg = 1;
    for (int i = 0; i < n; ++i) {
        ans += (s[i] - 'a' + 1) * deg;
        deg *= p;
    }
    return ans;
}
    
int main() {
    auto [first, second] = antihash_test();
    cout << "hash( " << first << " ) = " << _hash(first) << endl;
    cout << "hash( " << second << " ) = " << _hash(second) << endl;
    return 0;
}
