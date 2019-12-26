#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

constexpr int mod = 1000000007;

int distinct_subsequences(const string& s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    vector<int> prev(n, 0);
    unordered_map<char, int> pos;
    for (int i = 0; i < n; ++i) {
        prev[i] = pos[s[i]];
        pos[s[i]] = i + 1;
    }
       
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 2 * dp[i - 1];
        dp[i] %= mod;
        if (prev[i - 1]) dp[i] -= dp[prev[i - 1] - 1];
        dp[i] %= mod;
        dp[i] += mod;
        dp[i] %= mod;
    }
    return ((dp[n] - 1) % mod + mod) % mod;
}

int main() {
    
    string s;
    cin >> s;
    cout << distinct_subsequences(a) << endl;
    return 0;
}
