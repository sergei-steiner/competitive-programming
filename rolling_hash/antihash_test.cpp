#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
string ThueMorse(int n) {
    string ans(n, 'a');
    for (int i = 0; i < (1 << n); ++i) {
        ans[i] = __builtin_popcount(i) % 2 + 'a';
    }
    return ans;
}
    
int main() {
    int n;
    cin >> n;
    cout << ThueMorse(n) << endl;
    

    return 0;
}
