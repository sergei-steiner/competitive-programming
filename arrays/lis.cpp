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
    
int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << lengthOfLIS(a) << endl;
    
    return 0;
}
