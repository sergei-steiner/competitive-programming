#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// find positive mex (starting from 1)
// O(n) time 
// additional memory O(1)
// messing around with initial array is allowed

int mex(vector<int>& a) {
    int n = a.size();
    for (int& x : a) {
        if (x < 0 || x > n) x = 0;
    } 
    for (int i = 0; i < n; ++i) {
        int to = abs(a[i]);
        if (to == 0) continue;
        --to;
        if (a[to] > 0) a[to] *= -1;
        if (a[to] == 0) a[to] = -abs(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) return i + 1;
    }
    return n + 1;
}


int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << mex(a) << endl;
    
    return 0;
}
