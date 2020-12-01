#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/longest-increasing-subsequence

int lengthOfLIS(vector<int>& a) {
    int n = a.size();
    vector<int> d(n + 1, numeric_limits<int>::max());
    d[0]  = numeric_limits<int>::min();
    for (int x : a) {
        int i = upper_bound(d.begin(), d.end(), x) - d.begin();
        if (d[i - 1] != x) {
            d[i] = x;
        }
    }
    for (int i = n; i >= 0; --i) {
         if (d[i] < numeric_limits<int>::max()) {
             return i;
         }
    }
}

vector<int> LIS(vector<int>& a) {
    int n = a.size();
    vector<int> d(n + 1, numeric_limits<int>::max());
    d[0]  = numeric_limits<int>::min();
    vector<int> ind(n + 1, -1);
    vector<int> p(n, -1);
    
    d[0]  = numeric_limits<int>::min();
    for (int j = 0; j < n; ++j) {
        int x = a[j];
        int i = upper_bound(d.begin(), d.end(), x) - d.begin();
        if (d[i - 1] != x) {
            d[i] = x;
            ind[i] = j;
            p[j] = ind[i - 1];
            if (i + 1 <= n && ind[i+ 1] != -1) p[ind[i + 1]] = ind[i];
        }
    }
    for (int i = n; i >= 0; --i) {
         if (d[i] < numeric_limits<int>::max()) {
             int j = ind[i];
             vector<int> ans;
             while (j != -1) {
                 ans.push_back(j);
                 j = p[j];
             }
             reverse(begin(ans), end(ans));
             return ans;
         }
    }
}
    
int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << lengthOfLIS(a) << endl;
    for (int x : LIS(a)) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
