#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<int> z_func(const string& s) {
    int n = sz(s);
    vector<int> z(n, 0);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    vector<int> z = z_func(s);
    for (int i = 0; i < n; ++i) {
        cout << "z[" << i << "] = " << z[i] << endl;
    }
    return 0;
}
