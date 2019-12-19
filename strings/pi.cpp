#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

vector<int> pi_func(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
	while (j > 0  && s[i] != s[j]) j = pi[j - 1];
	if (s[i] == s[j]) ++j;
	pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    int n = sz(s);
    vector<int> pi = pi_func(s);
    for (int i = 0; i < n; ++i) {
        cout << "pi[" << i << "] = " << pi[i] << endl;
    }
    return 0;
}
