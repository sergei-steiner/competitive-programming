#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/product-of-array-except-self

vector<int> productExceptSelf(vector<int>& a) {
    int n = a.size();
    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] * a[i];
    }
    vector<int> suffix(n);
    suffix[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = a[i] * suffix[i + 1];
    }
    vector<int> ans(n, 1);
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
             ans[i] *= prefix[i - 1];    
        }
        if (i + 1 < n) {
            ans[i] *= suffix[i + 1];
        }
     }
     return ans;
 }

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int x : productExceptSelf(a)) {
        cout << x << " ";
    }
    return 0;
}
