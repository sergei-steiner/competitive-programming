// https://codeforces.com/contest/1419/problem/D2

#include <bits/stdc++.h>
 
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
 
typedef long long int64;
 
using namespace std;
    
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(all(a));
    vector<int> ans;
    int m = n / 2;
    for (int i = 0; i < m; ++i) {
        ans.push_back(a[i + m]);
        ans.push_back(a[i]);
    }
    if (n % 2 == 1) {
        ans.push_back(a[n - 1]);
    }
    int cnt = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if (ans[i - 1] > ans[i] && ans[i + 1] > ans[i]) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}
