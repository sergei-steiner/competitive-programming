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
        ans[i] = __builtin_popcount(i) % 2 + 'A';
    }
    return ans;
}


// should work for any rolling hash modulo 2^32

pair<string, string> antihash_test() {
    string s = ThueMorse(14);
    int n = s.size() / 2;
    return {s.substr(0, n), s.substr(n)};
}
    
int main() {
    int n;
    cin >> n;
    cout << ThueMorse(n) << endl;
    

    return 0;
}
