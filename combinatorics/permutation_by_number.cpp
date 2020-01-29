#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;
    
vector<int> PermutationByNumber(int n, int k) {
    vector<int> f(n, 1);
    for (int i = 2; i <  n; ++i) f[i] = f[i - 1] * i;
    vector<int> ans;
    vector<int> used(n, false);
    for (int i = 0; i < n; ++i) {
        int cnt = (k - 1) / f[n - i - 1];
        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;
            --cnt;
            if (cnt == 0) {
                ans.push_back(j + 1);
                used[j] = true;
                break;
            }
        }
    }
    return ans;
}
    
int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int x : PermutationByNumber(n, k)) {
        cout << x << " ";
    }
    return 0;
}
