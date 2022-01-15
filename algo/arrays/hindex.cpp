    
#include <bits/stdc++.h>

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

using namespace std;

// https://leetcode.com/problems/h-index

int hIndex(vector<int>& a) {
    int n = a.size();
    vector<int> cnt(n + 1, 0);
    for (int x : a) {
        ++cnt[min(x, n)];
    }
    int ind = 0;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            a[ind++] = i;
        }
    }
    return hIndexSorted(a);
}


// https://leetcode.com/problems/h-index-ii

int hIndexSorted(vector<int>& a) {
    int n = a.size();
    int l = 0;
    int r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] >= n - m) {
             r = m;
        } else {
             l = m + 1;
        }
    }
    return n - r;
}

int main() {

    return 0;
}
