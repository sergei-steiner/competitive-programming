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
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        int cnt = k / f[n - i - 1];
        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;
            --cnt;
            if (cnt == 0) {
                ans.push_back(j + 1);
                used[j] = true;
                break;
            }
        }
        k %= f[n - i - 1];
    }
    return ans;
}

int NumberOfPermutation(const vector<int>& p) {
    int n = p.size();
    vector<int> f(n, 1);
    for (int i = 2; i <  n; ++i) f[i] = f[i - 1] * i;
    
    int ans = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < p[i]; ++j) {
            if (used[j]) continue;
            ++cnt;
        }
        ans += cnt * f[n - i - 1];
        used[p[i]] = true;
    }
    return ans;
}
    
int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    auto p = PermutationByNumber(n, k);
    for (int x : p) {
        cout << x << " ";
    }
    cout << NumberOfPermutation(p) << endl;
    return 0;
}
