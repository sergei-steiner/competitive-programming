#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

/*

https://youtu.be/pwpOC1dph6U

There are N wines in a row.
Each year you sell either the leftmost or the rightmost wine.
The i-th wine has initial price p[i] and pruce k * p[i] in the k-th year.
What is the maximum possible total profit?

*/

// bottop-up

int solution1(const vector<int>& p) {
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) dp[i][i] = p[i] * n;
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            int year = i + n - j;
            dp[i][j] = max(year * p[i] + dp[i + 1][j], year * p[j] + dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}

int solution2(const vector<int>& p) {
    int n = p.size();
    return 0;
}

int solution3(const vector<int>& p) {
    int n = p.size();
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    cout << solution1(p) << endl;
    cout << solution2(p) << endl;
    cout << solution3(p) << endl;

    return 0;
}
